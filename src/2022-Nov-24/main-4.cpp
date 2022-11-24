#include <cppminimal>
#include <cstring>
#include <functional>

constexpr auto strSize = 200;

template <class callback>
void remove_on_condition(char* str, size_t size, callback cond) {
    for (decltype(size) i = 0; i < size; i++) {
        if (cond(str[i])) {
            for (decltype(size) j = i; j < size; j++) {
                str[j] = str[j+1];
            }
            size--;
            i--;
        }
    }
}

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};

    std::cin.getline((char*)str, strSize);

    remove_on_condition((char*)str, strlen((char*)str), [](char ch) -> bool {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    });

    std::cout << (char*)str << std::endl;
}