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

SKIP_VIRTUAL_FUNCS: Final[bool] = False


class ScrewYou3Macro(str, Enum):
    BEGIN = "SCREWYOU3_HOOK_BEGIN"
    HOOK = "SCREWYOU3_HOOK"
    FUNC_HOOK = "SCREWYOU3_HOOK_IMPL"
    MENULAYER_FUNC_HOOK = "SCREWYOU3_MENULAYER_CUSTOM_INIT"
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
    
    def __init__(self, name: str, typeName: str) -> None:
        self.name = name
        self.typeName = typeName
    
    @property
    def isPointer(self) -> bool:
        return "*" in self.typeName
    
    @property
    def isReference(self) -> bool:
        return "&" in self.typeName
    
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
        
        if self.typeName == "void":
            if finalVarName: raise Exception(f"Cannot set a 'void' value to a local var ('{finalVarName}')")
            else: return f"return;"
        
        baseNullptrCase = f"""
if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    {prefix} {Param.NULLPTR_POINTER if self.isPointer else Param.NULLPTR_REFERENCE};
"""

        if self.isPointer or self.isReference:
            res += baseNullptrCase
        
        if finalVarName: res += f"{self.typeName.replace("const", "").replace("static", "")} {finalVarName};\n"
        if self.isTypeValid():
            res += 'if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))\n\t'
            if self.isString():
                # bad assumption but we'll assume that pointer strings are always 'const char*'s
                randomCharsFunc = "getRandomCharSequence_c" if self.isPointer else "getRandomCharSequence"
                res += f'{prefix} modUtils::{randomCharsFunc}(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));'
            elif self.isNumerical() or self.isBoolean():
                min = "0" if self.isBoolean() else 'Mod::get()->getSettingValue<double>("gibberish-data-numerical-min")'
                max = "1" if self.isBoolean() else 'Mod::get()->getSettingValue<double>("gibberish-data-numerical-max")'
                res += f'{prefix} modUtils::chooseRandomNum({min}, {max});'
                
            # kinda hacky to replace 'const' like that but shh
            #
            # let's just pray it has a default ctor
            # we'll see when the mod is building anyway
            res += f"\n{prefix} {"new" if self.isPointer or self.isReference else ""} {self.typeNameAsVar()}();" \
                .replace("const", "", 1).replace("unsigned", "", 1).replace("signed", "", 1)
                                         
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
        
        withoutPointer = rawStr.replace("*", "").replace("&", "")
        name = withoutPointer.split(" ")[-1]
        # getting everything except the last word
        typeName = " ".join(rawStr.split(" ")[:-1]).strip()
        
        inst = cls.__new__(cls)
        inst.__init__(name, typeName)
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
    signature: str
    
    def __init__(self, signature: str, originClass: str, params: str, platforms: set[Platform]) -> None:
        self.signature = signature
        self.originClass = originClass
        self.platforms = platforms
        self.params = Param.fromRaws(params.split(",")) if params else []
    
    @property
    def funcName(self) -> str:
        return CPPFunction.getFuncName(self.signature)
    
    @property
    def returnType(self) -> str:
        return CPPFunction.getReturnType(self.signature)

    @property
    def isStatic(self) -> bool:
        return CPPFunction.getIfIsStatic(self.signature)

    @property
    def isVirtual(self) -> bool:
        return CPPFunction.getIfIsVirtual(self.signature)
    
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
        return Param(self.funcName + "_return", self.returnType).getValueChanger()
    
    def createParamsOverride(self) -> str:
        dynamicValueChanges: list[str] = []
        
        for param in self.params:
            dynamicValueChanges.append(param.getValueChanger(param.name))
            
        return "\n".join(dynamicValueChanges)
    
    def paramsToStr(self) -> str:
        return ", ".join(str(param) for param in self.params)
    
    # This is the most unreadable thing ever
    def codegen(self, hook_macro: ScrewYou3Macro = ScrewYou3Macro.HOOK, func_hook: ScrewYou3Macro = ScrewYou3Macro.FUNC_HOOK) -> str:
        """'Codegen' this function into a geode hook

        Args:
            hook_macro: The macro used to **hook** the function.
            func_hook: The macro that will have the content of the hook.
        """
        
        return CPPFunction.codegenHooks([self], hook_macro, func_hook)
    
    def __repr__(self) -> str:
        return f"CPPFunction({self.returnType} {self.funcName}({self.paramsToStr()}); , params = {self.params}, platforms = {self.platforms}))"
    
    def __hash__(self) -> int:
        return hash(frozenset(self.params)) + hash(self.returnType) + hash(self.funcName)
    
    def __eq__(self, value: object) -> bool:
        if isinstance(value, CPPFunction):
            return self.params == value.params and self.returnType == value.returnType and self.funcName == value.funcName and self.platforms == value.platforms
        elif isinstance(value, str):
            return self.originClass + "::" + self.funcName == value
        else:
            return False
    
    @staticmethod
    def codegenHooks(functions: "list[CPPFunction]", hook_macro: ScrewYou3Macro = ScrewYou3Macro.HOOK, func_hook: ScrewYou3Macro = ScrewYou3Macro.FUNC_HOOK) -> str:
        if len(functions) == 0: return ""
        
        originClass = functions[0].originClass
        funcName = functions[0].funcName
        
        hookBegin = f"{ScrewYou3Macro.BEGIN.value}({originClass})"
        includeCall = f"#include <Geode/modify/{originClass}.hpp>"
        
        ret = includeCall + "\n\n"
        
        # stores the name of the classes which return overrider already got written
        returnOverridesWritten: list[str] = []
        returnOverrides: str = ""
        for func in functions:
            if func.isVirtual and SKIP_VIRTUAL_FUNCS: # we're not hooking virtual functions
                functions.remove(func)
                continue
            if func.funcName in returnOverridesWritten:
                continue
            
            if func.originClass != originClass: raise Exception(f"Func {func} has not the same origin class as the other functions (which is '{originClass}')")
            
            funcReturnOverrideName = f"{originClass}_{func.funcName}_override()"
            funcReturnOverride = func.returnType + " " + funcReturnOverrideName + " {" + f"\n{func.createReturnOverride()}" + "\n}"
            
            returnOverrides += f"{funcReturnOverride}\n\n"
            returnOverridesWritten.append(func.funcName)
        
        ret += returnOverrides + "\n" + hookBegin
        
        for func in functions:
            # applying custom hook macro for MenuLayer::init
            _funcHook: ScrewYou3Macro
            # if func.originClass == "MenuLayer" and func.funcName == "init":
            if func == "MenuLayer::init":
                _funcHook = ScrewYou3Macro.MENULAYER_FUNC_HOOK
            else:
                _funcHook = func_hook
        
            if func.isVirtual and SKIP_VIRTUAL_FUNCS: # we're not hooking virtual functions
                continue
            
            ifDefs = func.createIfdefs()
            
            hookCall = f"{hook_macro.value}({func.signature.replace("virtual", "", 1).strip()})"
            
            if func.params == []:
                funcHookCall = f"{_funcHook.value}({originClass}, {func.funcName}, )"
            else:
                funcHookCall = f"{_funcHook.value}({originClass}, {func.funcName}, {removeTypes(func.paramsToStr())})"
            
            if ifDefs:
                ret += f"""
{ifDef}
{hookCall}
{funcHookCall}
#endif"""
            else:
                ret += f"""
{hookCall}
{funcHookCall}"""
        
        return ret + f"\n{ScrewYou3Macro.END.value}(\"{originClass}::{funcName}\")\n\n"
    
    @staticmethod
    def getReturnType(funcSignature: str) -> str:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return " ".join(splitted[:i]).replace("static", "", 1).replace("virtual", "", 1).strip()
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")
    
    @staticmethod
    def getFuncName(funcSignature: str) -> str:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return thing[:thing.find("(")]
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")
    
    @staticmethod
    def getIfIsStatic(funcSignature: str) -> bool:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return "static" in " ".join(splitted[:i])
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")

    @staticmethod
    def getIfIsVirtual(funcSignature: str) -> bool:
        splitted = funcSignature.split(" ")
        for i, thing in enumerate(splitted):
            if "(" in thing:
                return "virtual" in " ".join(splitted[:i])
        
        raise ValueError(f"Was given '{funcSignature}' but it wasn't indentified as a valid function")
    
    @staticmethod
    def getParamsAsStr(funcSignature: str) -> str:
        return funcSignature[funcSignature.find("(") + 1:funcSignature.find(")")]
        
def removeTemplateFormatting(params: str) -> str:
    if not "<" in params: return params
    
    # ret = ""
    
    # lastPos = 0
    # for i in range(params.count("<")): # opening of a template thingy
    #     openerPos = params.find("<", lastPos + 1)
    #     ret += params[lastPos:openerPos]
    #     ret += params[openerPos:params.find(">", lastPos) + 1].replace(" ", "").replace(",", "[THIS IS A SOMETHING BTW]")
        
    #     lastPos = openerPos
    
    # return ret
    
    return re.sub(r"<(\w+,( |)).+?>", "", params)

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
    
    params = removeTemplateFormatting(string).replace(", ", ",").strip().split(",")
    newParams: list[str] = list()
    for i, param in enumerate(params):
        _param = removeTotallyNotNeededCPPfeaturesThatNobodyWillEverNeed(param).replace("[THIS IS A SOMETHING BTW]", ",") # TODO: test this
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
    functions: dict[str, list[CPPFunction]] = {}
    unavailableFuncs: int = 0
    classesFoundByPlatforms: dict[CPPFunction.Platform, int] = {
        "win": 0,
        "android": 0,
        "ios": 0,
        "imac": 0,
        "m1": 0
    }
    numOfHookedFuncs: int = 0
    
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


    # incredible code below
    # WARNING: You have no right to get jealous of my coding skills
    with open(gdBromaFile) as classes:
        # regex = r"(|.+?link\(android.+?\n)(class (\w)+)|((bool init\(.+\))|(bool init\(\))) =[\w, ]+;" # fire regex
        bromaParserRegex = r"(|.+?link\(android.+?\n)(class (\w)+)|(.+\(.+\)|(.+\(\))) =[\w, ]+;" # it's maybe worse now
        matches = re.finditer(bromaParserRegex, classes.read(), re.MULTILINE | re.IGNORECASE)
        
        for match in matches:
            if ";" in match.group(): # a function declaration
                if "=" in match.group():
                    funcSignature, unparsedPlatforms = match.group().strip().split("=")
                else:
                    continue
                    #funcSignature, unparsedPlatforms = (match.group().strip(), "")
                
                funcSignature = funcSignature.strip()
                unparsedPlatforms = unparsedPlatforms.strip()
                if funcSignature.startswith("//"):
                    print(f"Skipping function '{funcSignature.removeprefix("//").strip()}' because it's commented")
                    continue
                
                params = addArgs(CPPFunction.getParamsAsStr(funcSignature))
                
                if any(x in unparsedPlatforms for x in ("win", "m1", "imac", "ios")):
                    # this regex is used to remove the adresses of the platform's functions
                    # it starts from the first adress up until the semicolon
                    removePlatformsRegex = r" 0x.+?(,|;)|inline(,|;)"
                    platforms: set[CPPFunction.Platform] = cast(set[CPPFunction.Platform], set(re.sub(removePlatformsRegex, "", unparsedPlatforms).strip().removeprefix("=").strip().split(" ")))
                    if isValidForAndroid: platforms.add("android")
                    for platform in platforms:
                        if classesFoundByPlatforms.get(platform) == None: print(f"  Platform '{platform}' not found in 'classesFoundByPlatforms'")
                        else: classesFoundByPlatforms[platform] += 1
                    
                    if functions.get(currentClass) == None:
                        functions[currentClass] = [CPPFunction(funcSignature, currentClass, params, platforms)]
                    else:
                        functions[currentClass].append(CPPFunction(funcSignature, currentClass, params, platforms))
            else:
                isValidForAndroid = False
                if not functions.get(currentClass) and currentClass != "":
                    unavailableFuncs += 1
                    #print(f"    {currentClass} is not avalaible on any platforms")
                
                if "link(android)" in "".join([match.group(), match.group(1)]):
                    isValidForAndroid = True
                    currentClass = match.group().replace("class ", "").split("\n")[1]
                else:
                    currentClass = match.group().replace("class ", "")
    
    print(f"Found {len(functions)} classes with {unavailableFuncs} unavailable classes (= they don't have bindings) !")
    print("Now creating files...")
    
    # functions.hpp
    
    with open(path("functions.hpp"), "w") as f:
        print("Creating 'functions.hpp'")
        getClassesFunc = """
constexpr std::vector<std::string> getClasses() {
	std::vector<std::string> ret;
    ret.reserve(getFuncs().size());

    for (auto& [clazz, funcs] : getFuncs()) {
        ret.push_back(clazz);
    }

	return ret;
}
"""
        
        text = """// Generated using 'generate.py'
#include <map>
#include <string>

using ScrewYouFuncsT = std::map<std::string, std::vector<std::string>>;

template<typename K, typename V>
constexpr void addToMap(std::map<K, V>& map, std::string clazz, std::string func) {
    if (map.contains(clazz)) {
        map.at(clazz).push_back(func);
	} else {
		std::vector<std::string> toInsert;
		toInsert.push_back(func);
        map[clazz] = toInsert;
	}
}

constexpr ScrewYouFuncsT getFuncs() {
    ScrewYouFuncsT classes;
    
"""

        for classFuncs in functions.values():
            for func in classFuncs:
                if not func.returnType in ALLOWED_TYPES: continue
                
                if func.isBindingAvalaible():
                    ifDef = func.createIfdefs()
                    if ifDef:
                        text += f"""\t{ifDef}
\taddToMap(classes, \"{func.originClass}\", \"{func.funcName}\");
\t#endif
"""
                    else:
                        text += f"\taddToMap(classes, \"{func.originClass}\", \"{func.funcName}\");\n"
                else:
                    text += f"\t// Bindings not avalaible for {func.originClass}::{func.funcName};\n"
                    
        text += "\n\treturn classes;\n}"
        f.write(text + "\n" + getClassesFunc)
    
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
// Also haii !!!
// :3

#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, funcName, ...) \\
    if (ScrewYou3Manager::get()->isKilled(fmt::format("{}::{}", className::CLASS_NAME, #funcName)) && Mod::get()->getSettingValue<bool>("enabled")) \\
        return className##_##funcName##_override(); \\
    else \\
		if (Mod::get()->getSavedValue<bool>("first-time-loading", true)) { \\
			Mod::get()->setSavedValue<bool>("first-time-loading", false); \\
			auto alert = FLAlertLayer::create( \\
				"Before you continue", \\
				"This mod CAN corrupt the game. Be sure to read this mod's description before continuing", \\
				"Dismiss" \\
			); \\
			alert->m_scene = this; \\
			alert->show(); \\
		} \\
        return className::funcName(__VA_ARGS__); \\
};

#define SCREWYOU3_HOOK_BEGIN(className) class $modify(Screwd##className, className) {
// I'm putting the min value for an int32 for the hook priority
// I'm terribly sorry but I had no choice
// (It's for the funnies :33)
#define SCREWYOU3_HOOK_END(hookedFunction) \\
    static void onModify(auto& self) { \\
        if (!self.setHookPriority(hookedFunction, -2147483648)) { \\
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

            for className, classFuncs in functions.items():
                funcsToCodegen: list[CPPFunction] = []
                for func in classFuncs:
                    if func.returnType in ALLOWED_TYPES: funcsToCodegen.append(func)
                text += CPPFunction.codegenHooks(funcsToCodegen)
                
                numOfHookedFuncs += len(funcsToCodegen)
                
                # for func in classFuncs:
                #     funcHookMacro = ScrewYou3Macro.MENULAYER_INIT if className == "MenuLayer" and func.funcName == "init" else ScrewYou3Macro.FUNC_HOOK
                #     if not func.isVirtual and SKIP_VIRTUAL_FUNCS: # We can't hook virtuals I think so yeah
                #         text += func.codegen(func_hook=funcHookMacro)
                    
            f.write(text)
            
    time2 = time.time()
    
    numOfFuncs = 0
    for funcs in functions:
        numOfFuncs += len(funcs)
    
    print("-" * 100)
    print("Done !")
    print(f"Finished in {time2 - time1} seconds !")
    print("Stats:")
    print(f"  Found {numOfFuncs} valid functions")
    print(f"  Found {unavailableFuncs} unavailable functions (They didn't have any binding)")
    print(f"  Hooked {numOfHookedFuncs} functions")
    print("  Platforms:")
    print(f"    Windows:      {classesFoundByPlatforms['win']}")
    print(f"    m1 (arm mac): {classesFoundByPlatforms['m1']}")
    print(f"    Android:      {classesFoundByPlatforms['android']}")
    print(f"    Imac:         {classesFoundByPlatforms['imac']}")
    print(f"    Ios:          {classesFoundByPlatforms['ios']}")
                
