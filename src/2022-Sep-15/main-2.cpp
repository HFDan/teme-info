/*
 * Să se scrie o funcție C++ care primește doi parametri a și b și afiseaza numărul obținut prin concatenarea lui a cu b.
 */

#include <iostream>
#include <type_traits>

static inline void nop() { __asm("nop"); }

template<typename T>
void func(T a, T b) {

  static_assert(std::is_integral<T>::value, "");

  std::cout << a << b << std::endl;
}

int main() { nop(); }
