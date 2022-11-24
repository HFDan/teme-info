#include <cppminimal>

constexpr auto strSize = 200;

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};
    std::ifstream ifs("prosir.in");
    
   ifs.getline((char*)str, strSize);
   
    for (auto* it = (char*)str; *it != '\0'; it++) {
        if ((*(it + 1) == ' ' || *(it + 1) == '.') && *it != ' ') {
           *it = '5'; 
        }
    }
    
    std::cout << (char*)str << std::endl;
}