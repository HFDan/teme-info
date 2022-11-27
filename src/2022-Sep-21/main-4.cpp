/*
 * Să se scrie definiția completă a funcției C++ P
 * care primește prin intermediul parametrului n un număr natural cu cel mult
 * 9 cifre, iar prin intermediul parametrului c o cifră.
 * Funcția întoarce tot prin intermediul parametrului n
 * numărul obținut prin eliminarea tuturor aparițiilor cifrei c.
 */
#include <cppminimal>

void P(uint32& n, const byte& c) {
    auto str = std::to_string(n);

    std::erase_if(str, [c](byte x) -> bool { return x == c; });

    n = std::stoi(str);
}

#include "./include_2.hpp"