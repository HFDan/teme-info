#include <cppminimal>
#include <cstring>

constexpr auto strSize = 200;

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};
    char rev[strSize] = {0};
    std::cin.getline((char*)str, strSize);
    
    strcpy(rev, str); 
    
    for (size_t i = 0; i < strlen(rev)/2; i++) {
        std::swap(rev[i], rev[strlen(rev) - i - 1]);
    }
    
    if (strcmp(str, rev) == 0)
        std::cout << "palindrom" << std::endl;
    else
        std::cout << "nu e" << std::endl;

    return 0;
}