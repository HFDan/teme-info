/*
* Să se scrie definiția completă a funcției C++ P
* care primește prin intermediul parametrului n un număr natural cu cel mult
* 9 cifre, iar prin intermediul parametrului c o cifră.
* Funcția întoarce tot prin intermediul parametrului n
* numărul obținut prin eliminarea tuturor aparițiilor cifrei c.
*/
#include "./include_1.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void P(uint32& n, const byte& c) {
    auto str = std::to_string(n);

    // Unintuitively, std::remove and std::remove_if do not remove anything,
    // they just move the non-passing elements to the end of the container.
    // We use std::string::erase to resize the container.
    str.erase(
        std::remove_if(

            str.begin(),
            str.end(),
            [c](byte x) -> bool {
                    return x == c;
                }

    ), str.end());

    n = std::stoi(str);
}

#include "./include_2.hpp"