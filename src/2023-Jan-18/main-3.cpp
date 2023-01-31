#include <bits/stdc++.h>

constexpr bool isVowel(char ch) { return strchr("AEIOUaeiou", ch) != nullptr; }

auto main(int argc, char** argv) -> int {

    char text[201];
    char cop[401] = {0};
    std::cin.getline(text, 200);

    int addto = 0;
    for (auto* ptr = text; *ptr != '\0'; ptr++) {
        if (isVowel(*ptr)) {
            cop[addto] = *ptr;
            cop[addto + 1] = 'p';
            cop[addto + 2] = *ptr;
            addto += 3;
        } else {
            cop[addto] = *ptr;
            addto++;
        }
    }
    
    std::cout << cop << std::endl;

    return 0;
}