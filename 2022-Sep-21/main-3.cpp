/*
* Să se scrie un subprogram C++ prin care se dublează prima cifră a unui număr
* natural n transmis ca parametru.
* Funcția întoarce rezultatul prin intermediul aceluiași parametru n.
*/

#include "./include_1.hpp"
#include <iostream>
#include <string>

void func(uint32& num) {
    auto str = std::to_string(num);

    str = str[0] + str;

    num = std::stoi(str);
    // Test change
}
#include "./include_2.hpp"