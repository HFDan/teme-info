#include <bits/stdc++.h>

auto main(int argc, char** argv) -> int {

    char text[201] = {0};
    char cautat[51];
    char inlocuit[51];
    std::cin.getline(text, 200);
    std::cin.getline(cautat, 50);
    std::cin.getline(inlocuit, 50);
    
    auto cautat_len = strlen(cautat);
    auto inlocuit_len = strlen(inlocuit);
    
    auto* found = strstr(text, cautat);
    while (found) {
        
        size_t found_idx = found-text;
        size_t difference = (cautat_len > inlocuit_len) ? cautat_len-inlocuit_len : inlocuit_len-cautat_len;
        
        // Verificam daca trebuie sa adaugam sau sa scoatem caractere
        if (inlocuit_len > cautat_len) {
            for (size_t i = 0; i < difference; i++) {
                for (size_t j = strlen(text); j > found_idx+i; j--) {
                    text[j+1] = text[j];
                }
            }
        } else {
            for (size_t i = 0; i < difference; i++) {
                for (size_t j = found_idx; j < strlen(text); j++) {
                    text[j] = text[j+1];
                }
            }
        }

        for (size_t i = 0, j = found_idx; i < inlocuit_len; i++, j++) {
            text[j] = inlocuit[i];
        }

        found = strstr(found, cautat);
    }

    std::cout << text << std::endl;

    return 0;
}