#include <cppminimal>

constexpr auto strSize = 200;

int main(int argc, char** argv) {
    char str[strSize] = {0};
    std::ifstream ifs("prosir.in");
    
   ifs.getline(str, strSize);
   
    for (auto* it = str; *it != '\0'; it++) {
        if ((*(it + 1) == ' ' || *(it + 1) == '.') && *it != ' ') {
           *it = '5'; 
        }
    }
    
    std::cout << str << std::endl;
}