#pragma once

#include <random>
#include <iterator>
#include <concepts>
#include <vector>

namespace modUtils {
    constexpr std::vector<char> getChars() {
        std::vector<char> res;

        constexpr char asciiMin = 32;
        constexpr char asciiMax = 126;

        for (char i = asciiMin; i < asciiMax; i++) {
            res.push_back(i);
        }

        return res;
    }

    template<typename T>
    concept arithmetic = std::integral<T> or std::floating_point<T>;

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

    /// Choses a random num from start to end
    template<arithmetic T>
    T chooseRandomNum(T start, T end) {
        return start + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (end-start)));
    }

    /// Choses a random num from 0 to end
    template<arithmetic T>
    T chooseRandomNum(T end) {
        return chooseRandomNum(0, end);
    }

    /// Gets a string of size 'lenght' filled with random characters
    inline std::string getRandomCharSequence(const size_t lenght) {
        std::string res;
        res.reserve(lenght);

        for (char i = 0; i < lenght; i++) {
            res += i;
        }

        return res;
    }
    inline const char* getRandomCharSequence_c(const size_t lenght) {
        std::string res;
        res.reserve(lenght);

        for (char i = 0; i < lenght; i++) {
            res += i;
        }

        const char* str = res.c_str();
        return str;
    }
}
