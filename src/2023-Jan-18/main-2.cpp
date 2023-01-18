#include <bits/stdc++.h>

inline bool isVowel(char ch) { return strchr("AEIOUaeiou", ch) != nullptr; }

auto main(int argc, char** argv) -> int {

    char cuv[25];
    char cop[50] = {0};
    std::cin >> cuv;

    int addto = 0;
    for (size_t i = 0; i < strlen(cuv); i++) {
        if (isVowel(cuv[i])) {
            cop[addto] = '#';
            cop[addto + 1] = 'v';
            cop[addto + 2] = cuv[i];
            addto += 3;
        } else {
            cop[addto] = cuv[i];
            addto++;
        }
    }
    
    std::cout << cop << std::endl;

    return 0;
}