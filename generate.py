"""Used to generate everything in the './src/generated' folder
"""

from enum import Enum
from pathlib import Path
import re
import argparse
import os
import time
from typing import Final, Literal, Optional, Self, TypeAlias, cast, overload
    

parser = argparse.ArgumentParser(
    description='Used to generated "./src/generated/"'
)

parser.add_argument("bindings_path", help="The path where the bindings for a game version is located. Those can be fetched from 'https://github.com/geode-sdk/bindings'")
parser.add_argument("-o", "--output", default="./src/",
                    help="The location of the output")


class ScrewYou3Macro(str, Enum):
    BEGIN = "SCREWYOU3_HOOK_BEGIN"
    HOOK = "SCREWYOU3_HOOK"
    FUNC_HOOK = "SCREWYOU3_HOOK_IMPL"
    MENULAYER_INIT = "SCREWYOU3_MENULAYER_CUSTOM_INIT"
    END = "SCREWYOU3_HOOK_END"
    
class Param:
    NULLPTR_POINTER: Final[str] = "nullptr"
    NULLPTR_REFERENCE: Final[str] = "*(int*)0)" # fire
    NUMERIC_TYPES: Final[tuple[str, ...]] = (
        "char", "signed char", "unsigned char",
        "short", "unsigned short",
        "int", "unsigned int",
        "long", "unsigned long",
        "long long", "unsigned long long",
        "float", "double", "long double"

        "int8_t", "uint8_t",
        "int16_t", "uint16_t",
        "int32_t", "uint32_t",
        "int64_t", "uint64_t",

        "int_least8_t", "uint_least8_t",
        "int_least16_t", "uint_least16_t",
        "int_least32_t", "uint_least32_t",
        "int_least64_t", "uint_least64_t",

        "int_fast8_t", "uint_fast8_t",
        "int_fast16_t", "uint_fast16_t",
        "int_fast32_t", "uint_fast32_t",
        "int_fast64_t", "uint_fast64_t",

        "intmax_t", "uintmax_t",
        "intptr_t", "uintptr_t"
    )
    STRING_TYPES: Final[tuple[str, ...]] = ("std::string", "gd::string", "const char*")
    
    name: str
    typeName: str
    isPointer: bool
    isReference: bool
    
    def __init__(self, name: str, typeName: str, isPointer: bool, isReference: bool) -> None:
        self.name = name
        self.typeName = typeName
        self.isPointer = isPointer
        self.isReference = isReference
    
    def isNumerical(self):
        return any(x in self.typeName for x in Param.NUMERIC_TYPES)
    
    def isString(self):
        return any(x in self.typeName for x in Param.STRING_TYPES)
    
    def isBoolean(self):
        return self.typeName == "bool"
    
    def isTypeValid(self):
        return self.isNumerical() or self.isString() or self.isBoolean()
    
    def typeNameAsVar(self):
        return self.typeName.replace("*", "").replace("&", "")
    
    @overload
    def getValueChanger(self, finalVarName: str):
        """Returns a snippet of code to dynamically change the value
        
        Params:
            finalVarName: the name of the variable from which to set the new value

        Returns:
            a snippet of code to dynamically change the value
        """
        ...
        
    @overload
    def getValueChanger(self):
        """Returns a snippet of code to dynamically change the value as is it's being returned in a function

        Returns:
            a snippet of code to dynamically change the value
        """
        ...
    
    def getValueChanger(self, finalVarName: Optional[str] = None) -> str:
        """Returns a snippet of code to dynamically change the value
        
        Params:
            finalVarName: the name of the variable from which to set the new value

        Returns:
            a snippet of code to dynamically change the value
        """
        
        prefix = "return" if finalVarName == None else finalVarName + " ="
        res = ""
        
        baseNullptrCase = f"""
if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    {prefix} {Param.NULLPTR_POINTER if self.isPointer else Param.NULLPTR_REFERENCE};
"""

        if self.isPointer or self.isReference:
            res += baseNullptrCase
        
        if finalVarName: res += f"{self.typeName} {finalVarName};\n"
        if self.isTypeValid():
            res += 'if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))\n\t'
            if self.isString():
                # bad assumption but we'll assume that pointer strings are always 'const char*'s
                randomCharsFunc = "getRandomCharSequence_c" if self.isPointer else "getRandomCharSequence"
                res += f'{prefix} modUtils::{randomCharsFunc}(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));'
            elif self.isNumerical() or self.isBoolean():
                res += f'{prefix} modUtils::chooseRandomNum(0, 1);'
                
            res += f"\n{prefix} {"new" if self.isPointer or self.isReference else ""} {self.typeNameAsVar()}();" # let's just pray it has a default ctor
                                                             # we'll see when the mod is building anyway
        return res
    
    def __str__(self) -> str:
        return f"{self.typeName} {self.name}"
    
    def __repr__(self) -> str:
        return f"Param({str(self)}, isPointer = {self.isPointer}, isReference = {self.isReference})"
    
    @classmethod
    def fromRaw(cls, rawStr: str) -> Self:
        # removing everything after the equal sign
        # (if there's one)
        if "=" in rawStr:
            rawStr = rawStr[:rawStr.find("=")].strip()
        
        isPointer = "*" in rawStr
        isReference = "&" in rawStr
        
        withoutPointer = rawStr.replace("*", "").replace("&", "")
        name = withoutPointer.split(" ")[-1]
        # getting everything except the last word
        typeName = " ".join(rawStr.split(" ")[:-1]).strip()
        
        inst = cls.__new__(cls)
        inst.__init__(name, typeName, isPointer, isReference)
        return inst
    
    @classmethod
    def fromRaws(cls, raws: list[str]) -> list[Self]:
        res: list[Self] = []
        
        for raw in raws:
            res.append(cls.fromRaw(raw))
        
        return res

class CPPFunction:
    Platform: TypeAlias = Literal["win", "imac", "m1", "ios", "android"]
    
    originClass: str
    params: list[Param]
    platforms: set[Platform]
    funcName: str
    returnType: str
    signature: str
    
    def __init__(self, signature: str, originClass: str, params: str, platforms: set[Platform]) -> None:
        self.signature = signature
        self.originClass = originClass
        self.platforms = platforms
        self.params = Param.fromRaws(params.split(","))
        self.funcName = CPPFunction.getFuncName(signature)
        self.returnType = CPPFunction.getReturnType(signature)
    
    def isWin(self): return "win" in self.platforms
    def isMac(self): return "imac" in self.platforms or "m1" in self.platforms
    def isIntelMac(self): return "imac" in self.platforms
    def isArmMac(self): return "m1" in self.platforms
    def isIos(self): return "ios" in self.platforms
    def isAndroid(self): return "android" in self.platforms
    
    def isBindingAvalaible(self):
        return self.isWin() or self.isMac() or self.isIos() or self.isAndroid()
    
    def isAvalaibleOnAllPlatforms(self):
        return self.isWin() and self.isMac() and self.isIos() and self.isAndroid()
    
    def createIfdefs(self):
        if not self.isBindingAvalaible() or self.isAvalaibleOnAllPlatforms(): return ""
        if self.platforms or self.platforms != ['']:
            ret = ""
            
            DEFINED_TEXT = "defined "
            
            win = "GEODE_IS_WINDOWS" if self.isWin() else ""
            android = "GEODE_IS_ANDROID" if self.isAndroid() else ""
            mac = "GEODE_IS_INTEL_MAC" if self.isIntelMac() else ""
            mac = "GEODE_IS_ARM_MAC" if self.isArmMac() else mac
            ios = "GEODE_IS_IOS" if self.isIos() else ""
            
            if win:
                ret += DEFINED_TEXT + win + " || "
            if android:
                ret += DEFINED_TEXT + android + " || "
            if mac:
                ret += DEFINED_TEXT + mac + " || "
            if ios:
                ret += DEFINED_TEXT + ios + " || "
            return "#if " + ret.removesuffix(" || ")
        return ""
    
    def createReturnOverride(self) -> str:
        return Param(self.funcName + "_return", self.returnType, False, False).getValueChanger()
    
    def createParamsOverride(self) -> str:
        dynamicValueChanges: list[str] = []
        
        for param in self.params:
            dynamicValueChanges.append(param.getValueChanger(param.name))
            
        # TODO: add return statement
        return "\n".join(dynamicValueChanges)
    
    def paramsToStr(self) -> str:
        return ", ".join(str(param) for param in self.params)
    
    # init_macro = INIT_MACRO
    # TODO: fix that
    
    # This is the most unreadable thing ever
    def build(self, hook_macro: ScrewYou3Macro = ScrewYou3Macro.HOOK):
        ifDefs = self.createIfdefs()

        if self.params == []:
            funcHookCall = f"{ScrewYou3Macro.FUNC_HOOK.value}({self.originClass}, {self.funcName}, )"
        else:
            funcHookCall = f"{ScrewYou3Macro.FUNC_HOOK.value}({self.originClass}, {self.funcName}, {removeTypes(self.paramsToStr())})"
        
        funcReturnOverrideName = f"{self.originClass}_{self.funcName}_override()"
        funcReturnOverride = self.returnType + " " + funcReturnOverrideName + " {" + f"\n{self.createReturnOverride()}" + "\n}"
        
        base = f"""{funcReturnOverride}\n\n{ScrewYou3Macro.BEGIN.value}({self.originClass})"""
        includeCall = f"#include <Geode/modify/{self.originClass}.hpp>"
        hookCall = f"{hook_macro.value}({self.signature})"
        
        ret: str = ""
        if ifDefs:
            ret = f"""
{ifDefs}
{base}
{includeCall}
{hookCall}
{funcHookCall}
{ScrewYou3Macro.END.value}()
#endif

"""
        else:
            ret = f"""{includeCall}
{base}
{hookCall}
{funcHookCall}
{ScrewYou3Macro.END.value}()

"""
        
        return ret
    
    @staticmethod
    def getReturnType(funcSignature: str) -> str:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return " ".join(splitted[:i])
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")
    
    @staticmethod
    def getFuncName(funcSignature: str) -> str:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return thing[:thing.find("(")]
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")
    

def addArgs(string: str):
    # :trol:
    def removeTotallyNotNeededCPPfeaturesThatNobodyWillEverNeed(string: str):
        return string.replace("const", "").replace("*", "").replace("&", "").strip()
        
    """Adds arguments to a c++ function

    Args:
        string: the arguments

    Returns:
        The arguments
    """
    
    if string == "": return ""
    
    params = string.replace(", ", ",").strip().split(",")
    newParams: list[str] = list()
    for i, param in enumerate(params):
        _param = removeTotallyNotNeededCPPfeaturesThatNobodyWillEverNeed(param)
        if (" " in _param or _param == ""):
            newParams.append(param)
            continue
        newParams.append(f"{param} p{i}")
    if len(newParams) == 0:
        return string.strip()
    
    ret = ", ".join(newParams)
    return ret

def removeTypes(string: str):
    """Removes the arguments from a c++ function

    Args:
        string: the argument string

    Returns:
        The arguments (without the types)
    """
    
    if string == "": return ""
    
    params = string.replace(", ", ",").strip().split(",")
    newParams: list[str] = []
    for param in params:
        splittedParams = param.split(" ")
        newParams.append(splittedParams[len(splittedParams) - 1])
    if len(newParams) == 0:
        return string.strip()
    
    ret = ", ".join(newParams)
    return ret

# yeah std::string isn't a primitive type but I don't care
# so shut up
PRIMITIVE_TYPES: Final[list[str]] = list(Param.NUMERIC_TYPES) + list(Param.STRING_TYPES) + ["bool"]
ALLOWED_TYPES: Final[list[str]] = PRIMITIVE_TYPES

if __name__ == "__main__":
    h = Param.fromRaw("std::string test").getValueChanger("finalVar")
    
    initFunctions: dict[str, CPPFunction] = {}
    unavailableClasses: int = 0
    classesFoundByPlatforms: dict[CPPFunction.Platform, int] = {
        "win": 0,
        "android": 0,
        "ios": 0,
        "imac": 0,
        "m1": 0
    }
    
    args = parser.parse_args()
    gdBromaFile = (Path(args.bindings_path) / "GeometryDash.bro").resolve()
    
    def path(file: str):
        return os.path.normpath(args.output + "\\generated\\" + file)

    currentClass: str = ""
    isValidForAndroid: bool = False

    if not os.path.exists(os.path.normpath(f"{args.output}/generated/")):
        print("Creating path", os.path.normpath(f"{args.output}/generated/"))
        os.mkdir(os.path.normpath(f"{args.output}/generated/"))

    print(f"Finding classes from {gdBromaFile}")

    time1 = time.time()


    with open(gdBromaFile) as classes:
        regex = r"(|.+?link\(android.+?\n)(class (\w)+)|((bool init\(.+\))|(bool init\(\))) =[\w, ]+;" # fire regex
        matches = re.finditer(regex, classes.read(), re.MULTILINE | re.IGNORECASE)
        
        for match in matches:
            if "bool init(" in match.group(): # a init() function:
                if " = " in match.group():
                    funcSignature, unparsedPlatforms = match.group().strip().split(" = ")
                else:
                    continue
                    #funcSignature, unparsedPlatforms = (match.group().strip(), "")
                
                params = addArgs(funcSignature.replace("bool init(", "").replace(")", ""))
                
                if any(x in unparsedPlatforms for x in ("win", "m1", "imac", "ios")):
                    platforms: set[CPPFunction.Platform] = cast(set[CPPFunction.Platform], set(re.sub(r" 0x.+?(,|;)", "", unparsedPlatforms).strip().removeprefix("=").strip().split(" ")))
                    if isValidForAndroid: platforms.add("android")
                    for platform in platforms:
                        if classesFoundByPlatforms.get(platform) == None: print(f"  Platform {platform} not found in 'classesFoundByPlatforms'")
                        classesFoundByPlatforms[platform] += 1
                    initFunctions[currentClass] = CPPFunction(funcSignature, currentClass, params, platforms)
            else:
                isValidForAndroid = False
                if not initFunctions.get(currentClass) and currentClass != "":
                    unavailableClasses += 1
                    #print(f"    {currentClass} is not avalaible on any platforms")
                
                _class: str
                if "link(android)" in "".join([match.group(), match.group(1)]):
                    isValidForAndroid = True
                    _class = match.group().replace("class ", "").split("\n")[1]
                else:
                    _class = match.group().replace("class ", "")
                    
                currentClass = f"{_class}"
    
    print(f"Found {len(initFunctions)} classes with {unavailableClasses} unavailable classes (= they don't have bindings for an 'init' function) !")
    print("Now creating files...")
    
    # classes.hpp
    
    with open(path("classes.hpp"), "w") as f:
        print("Creating 'classes.hpp'")
        text = """// Generated using 'generate.py'
#include <vector>
#include <string>

constexpr std::vector<std::string> getClasses() {
    std::vector<std::string> classes;
"""

        for func in initFunctions.values():
            if func.isBindingAvalaible():
                ifDef = func.createIfdefs()
                if ifDef:
                    text += f"""\t{ifDef}
\tclasses.push_back(\"{func.originClass}\");
\t#endif
"""
                else:
                    text += f"\tclasses.push_back(\"{func.originClass}\");\n"
        text += "\n\tclasses.shrink_to_fit();\n"
        text += "\treturn classes;\n}"
        f.write(text)
    
        # hooks.cpp
    
        with open(path("hooks.cpp"), "w") as f:
            print("Creating 'hooks.cpp'")
            text = """// Generated using 'generate.py'
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all

#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, ...) { \\
        if (ScrewYou3Manager::get()->isKilled(className::CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true; \\
        if (!className::init(__VA_ARGS__)) return false; \\
        if (Mod::get()->getSavedValue<bool>("first-time-loading", true)) { \\
            log::info("Showing popup"); \\
            Mod::get()->setSavedValue<bool>("first-time-loading", false); \\
            auto alert = FLAlertLayer::create( \\
                "Before you continue", \\
                "This mod CAN and WILL make your gd crash. Be sure to read this mod's description before continuing", \\
                "Dismiss" \\
            ); \\
            alert->m_scene = this; \\
            alert->show(); \\
        } \\
        return true; \\
    } \\
};

#define SCREWYOU3_HOOK_BEGIN(className) class $modify(Screwd##className, className) {
// I'm putting the min value for an int32 for the hook priority
// I'm terribly sorry but I had no choice
// (It's for the funnies :33)
#define SCREWYOU3_HOOK_END() \\
    static void onModify(auto& self) { \\
        if (!self.setHookPriority(-2147483648)) { \\
            geode::log::warn("hi"); \\
        } \\
    } \\
};

#define SCREWYOU3_HOOK(funcSignature) funcSignature {
#define SCREWYOU3_HOOK_IMPL(className, funcName, ...) \\
    if (ScrewYou3Manager::get()->isKilled(fmt::format("{}::{}", className::CLASS_NAME, #funcName)) && Mod::get()->getSettingValue<bool>("enabled")) \\
        return className##_##funcName##_override(); \\
    else \\
        return className::funcName(__VA_ARGS__); \\
};

// Hooking classes
// You might notice that the 'GEODE_IS_DEKSTOP' and 'GEODE_IS_MOBILE' macros aren't used, this is just because
// this file was automatically generated, so I just didn't want to bother with that, not like it was going
// to change a thing either way

"""

            for className, func in initFunctions.items():
                # TODO: fix second macro thingy
                init_macro = ScrewYou3Macro.MENULAYER_INIT if className == "MenuLayer" else ScrewYou3Macro.BEGIN
                # text += func.build(init_macro=init_macro)
                text += func.build()
            f.write(text)
            
    time2 = time.time()
    
    print("-" * 100)
    print("Done !")
    print(f"Finished in {time2 - time1} seconds !")
    print("Stats:")
    print(f"  Found {len(initFunctions)} init functions/valid classes")
    print(f"  Found {unavailableClasses} unavailable classes (They didn't have a 'init()' function)")
    print("  Platforms:")
    print(f"    Windows: {classesFoundByPlatforms['win']}")
    print(f"    m1 (arm mac): {classesFoundByPlatforms['m1']}")
    print(f"    Android: {classesFoundByPlatforms['android']}")
    print(f"    Imac: {classesFoundByPlatforms['imac']}")
    print(f"    Ios: {classesFoundByPlatforms['ios']}")
                
