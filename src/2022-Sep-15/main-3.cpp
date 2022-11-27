/*
 * Să se scrie o funcție C++ care primește un parametru x și și afiseaza cifra maxima a lui x
 */
#include <cppminimal>

void awesomeFunc(int x) {
    int max = 0;

    do {
        if (const int cifra = x % 10; cifra > max) max = cifra;

        x /= 10;
    } while (x > 0);

    std::cout << max;
}

auto main() -> int { nop(); }
