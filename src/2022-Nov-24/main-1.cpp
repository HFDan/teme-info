#include <cppminimal>

constexpr auto strSize = 100;

int main(int argc, char** argv) {
    
    char str[strSize] = {0};
    
    std::cin.getline(str, strSize);
    
    int counter = 0;

    for (int i = 1; i < strSize - 1 || str[i + 1] == '\0'; i++) {
        const auto prevch = str[i-1];
        const auto nextch = str[i+1];
        const auto ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            // Check prevch
            if (prevch != 'a' && prevch != 'e' && prevch != 'i' && prevch != 'o' && prevch != 'u' && !static_cast<bool>(std::isspace(prevch)) && nextch != '\0') {
                if (nextch != 'a' && nextch != 'e' && nextch != 'i' && nextch != 'o' && nextch != 'u' && !static_cast<bool>(std::isspace(nextch)) && nextch != '\0') {
                    counter++;
                }
            }
        }
    }
    
    std::cout << counter << std::endl;

    return 0;
}