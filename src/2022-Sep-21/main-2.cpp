/*
* Să se scrie o funcție C++ care să determine suma cifrelor pare și suma
* cifrelor impare pentru un număr natural transmis ca parametru.
* Funcția va întoarce rezultatele prin intermediul unor parametri de ieşire.
*/

#include "./include_1.hpp"
#include <iostream>

void func(uint32 num, uint32& pare, uint32& impare) {
    do {
        const int32 cifra = num % 10;

        if (cifra % 2 == 0)
            pare += cifra;
        else
            impare += cifra;

        num /= 10;
    } while (num > 0);
}

#include "./include_2.hpp"