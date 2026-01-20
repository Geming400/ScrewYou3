#include "ScrewYou3Manager.hpp"
#include "utils.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

ScrewYou3Manager* ScrewYou3Manager::get() {
    static ScrewYou3Manager* inst = new ScrewYou3Manager();
    return inst;
}

std::vector<std::string> ScrewYou3Manager::getSurvivingClasses() {
    return m_survivingClasses;
}

bool ScrewYou3Manager::isKilled(std::string className) {
    return !ranges::contains(m_survivingClasses, className);
}

void ScrewYou3Manager::killClass(std::string className) {
    log::info("Killed {}", className);
    ranges::remove(m_survivingClasses, className);
}

void ScrewYou3Manager::killRandomClass() {
    if (m_survivingClasses.empty()) return;
    
    auto killedClass = modUtils::select_randomly(m_survivingClasses.begin(), m_survivingClasses.end());
    log::info("Killed {}", *killedClass);
    m_survivingClasses.erase(killedClass);
}