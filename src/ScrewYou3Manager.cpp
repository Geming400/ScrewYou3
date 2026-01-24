#include "ScrewYou3Manager.hpp"
#include "Geode/loader/Log.hpp"
#include "utils.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool canLog() {
    return Mod::get()->getSettingValue<bool>("log");
}

std::string getFuncFromPath(std::string funcPath) {
    return utils::string::split(funcPath, "::")[1];
}

ScrewYou3Manager* ScrewYou3Manager::get() {
    static ScrewYou3Manager* inst = new ScrewYou3Manager();
    return inst;
}

ScrewYouFuncsT ScrewYou3Manager::getSurvivingFuncs() {
    return m_survivingFuncs;
}
std::vector<std::string> ScrewYou3Manager::getAllSurvivingFuncs(bool withNamespace) {
    std::vector<std::string> ret;

    for (auto& [clazz, funcs] : m_survivingFuncs) {
        for (auto& func : funcs) {
            if (withNamespace)
                ret.push_back(fmt::format("{}::{}", clazz, func));
            else
                ret.push_back(func);
        }
    }    

    return ret;
}


bool ScrewYou3Manager::isKilled(std::string funcPath) {
    for (auto& [clazz, funcs] : m_survivingFuncs) {
        if (ranges::contains(funcs, getFuncFromPath(funcPath))) {
            if (canLog()) log::debug("Checking if {} (func '{}') is killed: false", funcPath, getFuncFromPath(funcPath));
            return false;
        }
    }

    if (canLog()) log::debug("Checking if {} (func '{}') is killed: true", funcPath, getFuncFromPath(funcPath));
    return true;
}
bool ScrewYou3Manager::isKilled(std::string clazz, std::string funcName) {
    bool res = !ranges::contains(m_survivingFuncs.at(clazz), funcName);

    if (canLog()) log::debug("Checking if {}::{} is killed: {}", clazz, funcName, res);
    return res;
}

void ScrewYou3Manager::killClass(std::string funcPath) {
    for (auto& [clazz, funcs] : m_survivingFuncs) {
        if (ranges::contains(funcs, getFuncFromPath(funcPath))) {
            ranges::remove(funcs, getFuncFromPath(funcPath));
            log::info("Killed {}", funcPath);

            break;
        }
    }
}

void ScrewYou3Manager::killClass(std::string clazz, std::string funcName) {
    ranges::remove(m_survivingFuncs.at(clazz), funcName);
    log::info("Killed {}::{}", clazz, funcName);
}

void ScrewYou3Manager::killRandomClass() {
    if (m_survivingFuncs.empty()) return;

    std::vector<std::string> survivingFuncs = getAllSurvivingFuncs(true);
    
    auto killedClass = modUtils::select_randomly(survivingFuncs.begin(), survivingFuncs.end());
    killClass(*killedClass);
}