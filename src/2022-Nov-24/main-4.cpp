#include <cppminimal>
#include <cstring>

constexpr auto strSize = 200;

void remove_on_condition(char* str, size_t size, bool (*cond)(char)) {
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

int main(int argc, char** argv) {
    char str[strSize] = {0};

    std::cin.getline(str, strSize);

    remove_on_condition(str, strlen(str), [](char ch) -> bool {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    });

    std::cout << str << std::endl;
}