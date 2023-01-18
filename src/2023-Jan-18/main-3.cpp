#include <bits/stdc++.h>

inline bool isVowel(char ch) { return strchr("AEIOUaeiou", ch) != nullptr; }

auto main(int argc, char** argv) -> int {

    char text[201];
    char cop[401] = {0};
    std::cin.getline(text, 200);

    int addto = 0;
    for (size_t i = 0; i < strlen(text); i++) {
        if (isVowel(text[i])) {
            cop[addto] = text[i];
            cop[addto + 1] = 'p';
            cop[addto + 2] = text[i];
            addto += 3;
        } else {
            cop[addto] = text[i];
            addto++;
        }
    }
    
    std::cout << cop << std::endl;

    return 0;
}