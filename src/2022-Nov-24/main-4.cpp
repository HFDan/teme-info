#include <cppminimal>
#include <cstring>
#include <functional>

constexpr auto strSize = 200;

/**
 * @brief Elimina un element dintr-un vector bazat pe o conditie
 * 
 * @tparam callback 
 * @param str Sirul de caractere 
 * @param size Marimea sirului
 * @param cond Conditia. Pointer catre o functie de tip bool(char) care returneaza true daca carecterul trebuie sters
 */
template <class callback>
void remove_on_condition(char* str, size_t size, callback cond) {    
    // decltype e o functie speciala. Returneaza *TIPUL* unei variabile.
    // De exemplu:
    // pentru int x
    // decltype(x) va returna "int"
    // https://learn.microsoft.com/en-us/cpp/cpp/decltype-cpp?view=msvc-170
    using size_type = decltype(size);

    for (size_type i = 0; i < size; i++) {
        if (cond(str[i])) {
            for (size_type j = i; j < size; j++) {
                str[j] = str[j+1];
            }
            size--;
            i--;
        }
    }
    str[size] = '\0'; // Force null termination
}

auto main(int argc, char** argv) -> int {
    char str[strSize] = {0};

    std::cin.getline((char*)str, strSize);

    remove_on_condition((char*)str, strlen((char*)str), 
    // Aceasta este o "functie anonima". Poate fi folosita drept parametru in alte functii.
    // https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
        [](char chr) {
            return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u');
        }
    );

    std::cout << (char*)str << std::endl;
}