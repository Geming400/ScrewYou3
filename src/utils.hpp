#pragma once

#include <random>
#include <iterator>
#include <concepts>
#include <string>

namespace modUtils {
    constexpr char ASCII_MIN = 32;
    constexpr char ASCII_MAX = 126;

    template<typename T>
    concept arithmetic = std::integral<T> or std::floating_point<T>;

    template<typename T>
    concept uniformCompatible =
        std::integral<T>
        && !std::same_as<T, char>
        && !std::same_as<T, signed char>
        && !std::same_as<T, unsigned char>
        && !std::same_as<T, bool>;

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
    template<uniformCompatible T>
    T chooseRandomNum(T start, T end) {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<T> dist(start, end);
        return dist(rng);
    }
    template<std::floating_point T>
    T chooseRandomNum(T start, T end) {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<T> dist(start, end);
        return dist(rng);
    }
    inline char chooseRandomNum(char start, char end) {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(start, end);
        return static_cast<char>(dist(rng));
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
            res += chooseRandomNum(ASCII_MIN, ASCII_MAX);
        }

        return res;
    }
    inline const char* getRandomCharSequence_c(const size_t lenght) {
        std::string res;
        res.reserve(lenght);

        for (char i = 0; i < lenght; i++) {
            res += chooseRandomNum(ASCII_MIN, ASCII_MAX);
        }

        const char* str = res.c_str();
        return str;
    }
}
