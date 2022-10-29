/*
* Să se scrie o funcție C++ care să determine suma cifrelor unui număr natural
* transmis ca parametru. 
* Funcția întoarce rezultatul prin intermediul unui parametru de ieşire. 
*/

#include <cppminimal>

void func(uint32 num, uint32& retVal) {
    do {
        retVal += num % 10;
        num /= 10;
    } while (num > 0);
}

#include "./include_2.hpp"