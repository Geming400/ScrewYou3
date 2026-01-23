#include <Geode/Geode.hpp>
#include "ScrewYou3Manager.hpp"

using namespace geode::prelude;

#include <Geode/modify/PlayerObject.hpp>
class $modify(PlayerObjectButBetter, PlayerObject) {
    void playerDestroyed(bool p0) {
        PlayerObject::playerDestroyed(p0);

        // Testing this amazing mod
        // ScrewYou3Manager::get()->killClass("MenuLayer");
        for (size_t i = 0; i < Mod::get()->getSettingValue<int64_t>("intensity"); i++) {
            ScrewYou3Manager::get()->killRandomClass();
        }

        if (ScrewYou3Manager::get()->getSurvivingFuncs().size() == 0) {
            // We can't send a notification to the player or else the game would crash
            log::info("Gg !!!!");
            log::info("You won't be able to do anything now");
        }
    }
};
