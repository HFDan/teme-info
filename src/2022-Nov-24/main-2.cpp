#include <cppminimal>

constexpr auto strSize = 100;

constexpr auto isVowel(const char character) -> bool {
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'); 
}

auto main(int argc, char** argv) -> int {

    char str[strSize] = {0};
    
    std::cin.getline((char*)str, strSize);
    
    for (auto* it = (char*)str; *it != '\0'; it++) {
        const auto character = *it;
        if (isVowel(character)) {
            *it -= 32; // ASCII e plin de relatii matematice. Daca scazi 32 dintr-un caracter mare, vei ajunge la o litera mica.
        }
    }
    
    std::cout << (char*)str << std::endl;

    return 0;
}