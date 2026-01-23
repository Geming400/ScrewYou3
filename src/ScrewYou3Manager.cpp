#include "ScrewYou3Manager.hpp"
#include "utils.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

ScrewYou3Manager* ScrewYou3Manager::get() {
    static ScrewYou3Manager* inst = new ScrewYou3Manager();
    return inst;
}

ScrewYouFuncsT ScrewYou3Manager::getSurvivingFuncs() {
    return m_survivingClasses;
}


bool ScrewYou3Manager::isKilled(std::string funcPath) {
    for (auto& [clazz, funcs] : m_survivingClasses) {
        if (ranges::contains(funcs, funcPath)) return false;
    }

    return true;
}
bool ScrewYou3Manager::isKilled(std::string clazz, std::string funcName) {
    return !ranges::contains(m_survivingClasses.at(clazz), funcName);
}

void ScrewYou3Manager::killClass(std::string funcName) {
    for (auto& [clazz, funcs] : m_survivingClasses) {
        if (ranges::contains(funcs, funcName))
            ranges::remove(funcs, funcName);
    }

    
    log::info("Killed {}", funcName);
}

void ScrewYou3Manager::killClass(std::string clazz, std::string funcName) {
    ranges::remove(m_survivingClasses.at(clazz), funcName);
    log::info("Killed {}", funcName);
}

void ScrewYou3Manager::killRandomClass() {
    if (m_survivingClasses.empty()) return;
    
    auto killedClass = modUtils::select_randomly(m_survivingClasses.begin(), m_survivingClasses.end());
    log::info("Killed {}", *killedClass);
    m_survivingClasses.erase(killedClass);
}