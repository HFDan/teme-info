#include <cppminimal>

constexpr auto strSize = 100;

int main(int argc, char** argv) {

    char str[strSize] = {0};
    
    std::cin.getline(str, strSize);
    
    for (auto* it = str; *it != '\0'; it++) {
        const auto ch = *it;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            *it -= 32;
        }
    }
    
    std::cout << str << std::endl;

    return 0;
}