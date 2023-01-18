#include <bits/stdc++.h>
 
auto main(int argc, char** argv) -> int {

    char text[251];
    char x[20];
    std::cin.getline(text, 250);
    std::cin >> x;

    struct {
        const char* tokens[250];
        size_t size{0};
    } tokens;

    for (const char* tok = strtok(text, " ;"); tok != nullptr; tok = strtok(nullptr, " ;")) {
        tokens.tokens[tokens.size] = tok;
        tokens.size++;
    }
    
    int found = 0;
    for (size_t i = 0; i < tokens.size - 1; i++) {
        if (strcmp(tokens.tokens[i], x) == 0) {
            std::cout << tokens.tokens[i+1] << std::endl;
            found++;
        }
    }

    if (found == 0)
        std::cout << "NU" << std::endl;

    return 0;
}