// Generated using 'generate.py'
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all

// Will have to fix the signature and everything for this macro
#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, ...) { \
        if (ScrewYou3Manager::get()->isKilled(className::CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true; \
        if (!className::init(__VA_ARGS__)) return false; \
        if (Mod::get()->getSavedValue<bool>("first-time-loading", true)) { \
            log::info("Showing popup"); \
            Mod::get()->setSavedValue<bool>("first-time-loading", false); \
            auto alert = FLAlertLayer::create( \
                "Before you continue", \
                "This mod CAN and WILL make your gd crash. Be sure to read this mod's description before continuing", \
                "Dismiss" \
            ); \
            alert->m_scene = this; \
            alert->show(); \
        } \
        return true; \
    } \
};

#define SCREWYOU3_HOOK_BEGIN(className) class $modify(Screwd##className, className) {
// I'm putting the min value for an int32 for the hook priority
// I'm terribly sorry but I had no choice
// (It's for the funnies :33)
#define SCREWYOU3_HOOK_END() \
    static void onModify(auto& self) { \
        if (!self.setHookPriority(-2147483648)) { \
            geode::log::warn("hi"); \
        } \
    } \
};

#define SCREWYOU3_HOOK(funcSignature) funcSignature {
#define SCREWYOU3_HOOK_IMPL(className, funcName, ...) \
    if (ScrewYou3Manager::get()->isKilled(fmt::format("{}::{}", className::CLASS_NAME, #funcName)) && Mod::get()->getSettingValue<bool>("enabled")) \
        return className##_##funcName##_override(); \
    else \
        return className::funcName(__VA_ARGS__); \
};

// Hooking classes
// You might notice that the 'GEODE_IS_DEKSTOP' and 'GEODE_IS_MOBILE' macros aren't used, this is just because
// this file was automatically generated, so I just didn't want to bother with that, not like it was going
// to change a thing either way

#include <Geode/modify/AccountLoginLayer.hpp>
bool AccountLoginLayer_init_override() {
    bool p0;

    if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
        p0 = modUtils::chooseRandomNum(0, 1);

    return bool(p0);
}
SCREWYOU3_HOOK_BEGIN(AccountLoginLayer)
SCREWYOU3_HOOK(bool init(std::string p0))
SCREWYOU3_HOOK_IMPL(AccountLoginLayer, init, p0)
SCREWYOU3_HOOK_END()