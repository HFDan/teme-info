/*
 * Să se scrie o funcție C++ care primește doi parametri a și b și afiseaza numărul mai mare dintre a si b.
 */

#include <iostream>

static inline void nop() { __asm("nop"); }

void func(int a, int b) {
  std::cout << (a > b ? a : b) << std::endl;
}

int main() { nop(); }
