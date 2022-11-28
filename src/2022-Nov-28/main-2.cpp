#include <cppminimal>
#include <cstring>

constexpr auto strSize = 200;

constexpr auto isVowel(const char character) -> bool {
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'); 
}

auto findFirstVowel(const char* const str, size_t len) -> size_t {
    for (size_t i = 0; i < len; i++) {
        if (isVowel(str[i]))
            return i;
    }

    return len;
}

auto findLastConsonant(const char* const str, size_t len) -> size_t {
    for (size_t i = len-1; i >= 0; i++) {
        if (!isVowel(str[i]))
            return i;
    }

    return 0;
}

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};
    
    std::cin >> str;

    std::swap(str[findFirstVowel(str, strlen(str))], str[findLastConsonant(str, strlen(str))]);
    
    std::cout << str << std::endl;

    return 0;
}