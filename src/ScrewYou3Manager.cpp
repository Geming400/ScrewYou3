#include "ScrewYou3Manager.hpp"
#include "Geode/loader/Log.hpp"
#include "utils.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

std::string getFuncFromPath(std::string funcPath) {
    return utils::string::split(funcPath, "::")[1];
}

ScrewYou3Manager* ScrewYou3Manager::get() {
    static ScrewYou3Manager* inst = new ScrewYou3Manager();
    return inst;
}

ScrewYouFuncsT ScrewYou3Manager::getSurvivingFuncs() {
    return m_survivingClasses;
}


bool ScrewYou3Manager::isKilled(std::string funcPath) {
    for (auto& [clazz, funcs] : m_survivingClasses) {
        if (ranges::contains(funcs, getFuncFromPath(funcPath))) {
            log::debug("Checking if {} (func '{}') is killed: false", funcPath, getFuncFromPath(funcPath));
            return false;
        }
    }

    log::debug("Checking if {} (func {}) is killed: true", funcPath, getFuncFromPath(funcPath));
    return true;
}
bool ScrewYou3Manager::isKilled(std::string clazz, std::string funcName) {
    bool res = !ranges::contains(m_survivingClasses.at(clazz), funcName);

    log::debug("Checking if {}::{} is killed: {}", clazz, funcName, res);
    return res;
}

void ScrewYou3Manager::killClass(std::string funcPath) {
    for (auto& [clazz, funcs] : m_survivingClasses) {
        if (ranges::contains(funcs, funcPath)) {
            ranges::remove(funcs, getFuncFromPath(funcPath));
            log::debug("Killed {}", funcPath);

            break;
        }
    }
}

void ScrewYou3Manager::killClass(std::string clazz, std::string funcName) {
    ranges::remove(m_survivingClasses.at(clazz), funcName);
    log::info("Killed {}::{}", clazz, funcName);
}

void ScrewYou3Manager::killRandomClass() {
    if (m_survivingClasses.empty()) return;
    
    auto killedClass = modUtils::select_randomly(m_survivingClasses.begin(), m_survivingClasses.end());
    log::info("Killed {}", *killedClass);
    m_survivingClasses.erase(killedClass);
}