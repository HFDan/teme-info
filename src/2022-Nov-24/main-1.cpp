#include <cppminimal>

constexpr auto strSize = 100;

/**
 * @brief Verifica daca un caracter e vocala
 * 
 * @param character 
 * @return true 
 * @return false 
 */
constexpr auto isVowel(const char character) -> bool {
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'); 
}

auto main(int argc, char** argv) -> int {
    
    char str[strSize] = {0};
    
    std::cin.getline((char*)str, strSize);
    
    int counter = 0;

    for (int i = 1; i < strSize - 1 || str[i + 1] == '\0'; i++) {
        const auto prevch = str[i-1];
        const auto nextch = str[i+1];
        const auto ch = str[i];
        if (isVowel(ch) && !isVowel(prevch) && !isVowel(nextch) && !static_cast<bool>(std::isspace(prevch)) && !static_cast<bool>(std::isspace(nextch)) && nextch != '\0') {
                    counter++;
        }
    }
    
    std::cout << counter << std::endl;

    return 0;
}