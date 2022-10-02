/*
 * Să se scrie o funcție C++ care primește un parametru x și și afiseaza cifra maxima a lui x
 */
#include <iostream>

static inline void nop() { __asm("nop"); }

void awesomeFunc(int x) {
  
  int max = 0;

  do {
    
    const int cifra = x % 10;
    if (cifra > max)
      max = cifra;

    x /= 10;
  } while (x);

  std::cout << max;

}

int main() { nop(); }