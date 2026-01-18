"""Used to generate everything in the './src/generated' folder
"""

import re
import argparse
import os
import time
from typing import Final, Self

HOOK_MACRO: Final[str] = "SCREWYOU3_HOOK"
INIT_MACRO: Final[str] = "SCREWYOU3_HOOK_INIT"
MENULAYER_CUSTOM_INIT_MACRO: Final[str] = "SCREWYOU3_MENULAYER_CUSTOM_INIT"

parser = argparse.ArgumentParser(
    description='Used to generated "./src/generated/"'
)

parser.add_argument("geometrydash_broma_file")
parser.add_argument("-o", "--output", default="./src/",
                    help="The location of the output")
parser.add_argument("-i", "--ignore", default="",
                    help="A list of classes to ignore. Each elements is separated by a semi-colon")

class Param:
    name: str
    typeName: str
    isPointer: bool
    isReference: bool
    
    def __init__(self, name: str, typeName: str, isPointer: bool, isReference: bool) -> None:
        self.name = name
        self.typeName = typeName
        self.isPointer = isPointer
        self.isReference = isReference
        
    @classmethod
    def fromRaw(cls, rawStr: str) -> Self:
        rawStr = rawStr[:rawStr.find("=")].strip()
        # const char* str;
        
        isPointer = "*" in rawStr
        isReference = "&" in rawStr
        
        name = ""
        typeName = ""
        
        inst = cls.__new__(cls)
        inst.__init__(name, typeName, isPointer, isReference)
        return inst
        

class CPPFunction:
    name: str
    params: str
    platforms: set[str]
    
    def __init__(self, name: str, params: str, platforms: set[str]) -> None:
        self.name = name
        self.params = params
        self.platforms = platforms
    
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
    
    def build(self, hook_macro: str = HOOK_MACRO, init_macro: str = INIT_MACRO):
        ifDefs = self.createIfdefs()

        if self.params == "":
            initMacroCall = f"{init_macro}({self.name})"
        else:
            initMacroCall = f"{init_macro}({self.name}, {removeTypes(self.params)})"
        
        includeCall = f"#include <Geode/modify/{self.name}.hpp>"
        hookCall = f"""{hook_macro}({self.name}, {self.params})
{initMacroCall}"""
        
        ret: str = ""
        if ifDefs:
            ret = f"""
{ifDefs}
{includeCall}
{hookCall}
#endif

"""
        else:
            ret = f"""{includeCall}
{hookCall}

"""
        
        return ret
    

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
    

if __name__ == "__main__":
    initFunctions: dict[str, CPPFunction] = {}
    unavailableClasses: int = 0
    classesFoundByPlatforms: dict[str, int] = {
        "win": 0,
        "android": 0,
        "ios": 0,
        "imac": 0,
        "m1": 0
    }
    
    args = parser.parse_args()
    
    toIgnore: list[str] = args.ignore.lower().split(";")
    
    def path(file: str):
        return os.path.normpath(args.output + "\\generated\\" + file)

    currentClass: str = ""
    isValidForAndroid: bool = False

    if not os.path.exists(os.path.normpath(f"{args.output}/generated/")):
        print("Creating path", os.path.normpath(f"{args.output}/generated/"))
        os.mkdir(os.path.normpath(f"{args.output}/generated/"))

    print(f"Finding classes from {os.path.normpath(args.geometrydash_broma_file)}")

    time1 = time.time()

    with open(os.path.normpath(args.geometrydash_broma_file)) as classes:
        regex = r"(|.+?link\(android.+?\n)(class (\w)+)|((bool init\(.+\))|(bool init\(\))) =[\w, ]+;" # fire regex
        matches = re.finditer(regex, classes.read(), re.MULTILINE | re.IGNORECASE)

        ignoreNextInitFunc: bool = False
        
        for match in matches:
            if "bool init(" in match.group(): # a init() function:
                if ignoreNextInitFunc:
                    ignoreNextInitFunc = False
                    continue
                
                if " = " in match.group():
                    funcSignature, unparsedPlatforms = match.group().strip().split(" = ")
                else:
                    continue
                    #funcSignature, unparsedPlatforms = (match.group().strip(), "")
                
                params = addArgs(funcSignature.replace("bool init(", "").replace(")", ""))
                
                if any(x in unparsedPlatforms for x in ("win", "m1", "imac", "ios")):
                    platforms = set(re.sub(r" 0x.+?(,|;)", "", unparsedPlatforms).strip().removeprefix("=").strip().split(" "))
                    if isValidForAndroid: platforms.add("android")
                    for platform in platforms:
                        if classesFoundByPlatforms.get(platform) == None: print(f"  Platform {platform} not found in 'classesFoundByPlatforms'")
                        classesFoundByPlatforms[platform] += 1
                    initFunctions[currentClass] = CPPFunction(currentClass, params, platforms)
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
                    
                if any(x in _class.lower() for x in toIgnore) and toIgnore != ['']:
                    print(f"    Ignoring class {_class}")
                    ignoreNextInitFunc = True
                    continue
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
\tclasses.push_back(\"{func.name}\");
\t#endif
"""
                else:
                    text += f"\tclasses.push_back(\"{func.name}\");\n"
        text += "\n\tclasses.shrink_to_fit();\n"
        text += "\treturn classes;\n}"
        f.write(text)
    
        # hooks.cpp
    
        with open(path("hooks.cpp"), "w") as f:
            print("Creating 'hooks.cpp'")
            text = """// Generated using 'generate.py'
// Can't wait for someone to destroy `PlayerObject`'s as their first destroyed init :3
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all

#define SCREWYOU2_MENULAYER_CUSTOM_INIT(className, ...) { \\
        if (ScrewYou3Manager::get()->isKilled(CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true; \\
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

#define SCREWYOU3_HOOK(className, ...) \\
class $modify(Screwd##className, className) { \\
    bool init(__VA_ARGS__) // `SCREWYOU3_HOOK_INIT()` macro goes here

#define SCREWYOU3_HOOK_INIT(className, ...) { \\
        if (ScrewYou3Manager::get()->isKilled(CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true;\\
        if (!className::init(__VA_ARGS__)) return false; \\
        return true; \\
    } \\
};

// Hooking classes
// You might notice that the 'GEODE_IS_DEKSTOP' and 'GEODE_IS_MOBILE' macros aren't used, this is just because
// this file was automatically generated, so I just didn't want to bother with that, not like it was going
// to change a thing either way

"""

            for className, func in initFunctions.items():
                init_macro = MENULAYER_CUSTOM_INIT_MACRO if className == "MenuLayer" else INIT_MACRO
                text += func.build(init_macro=init_macro)
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
                
