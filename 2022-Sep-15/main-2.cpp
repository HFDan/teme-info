/*
 * Să se scrie o funcție C++ care primește doi parametri a și b și afiseaza numărul obținut prin concatenarea lui a cu b.
 */

#include <iostream>

static inline void nop() { __asm("nop"); }

template<typename T>
void func(T a, T b) {
  std::cout << a << b;
}

int main() { nop(); }
