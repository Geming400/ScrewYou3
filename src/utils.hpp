#pragma once

#include <random>
#include <iterator>

namespace modUtils {
    // Literally stolen from https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container
    // because I can use CTRL+C and CTRL+V :trol:

    template<typename Iter, typename RandomGenerator>
    Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(g));
        return start;
    }

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }
}
