#include <cppminimal>
#include <cstring>

constexpr auto strSize = 200;

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};
    
    std::cin.getline((char*)str, strSize);
    
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i+1] == ' ' || str[i+1] == '\0' || i == 0 || str[i-1] == ' ')
            str[i] -= 32;
    }
    
    std::cout << str << std::endl;

    return 0;   
}