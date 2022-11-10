/*
 * Să se scrie o funcție C++ care primește doi parametri a și b și afiseaza numărul obținut prin concatenarea lui a cu
 * b.
 */

#include <cppminimal>

template <typename T>
void func(T a, T b) {
    static_assert(std::is_integral_v<T>);

    std::cout << a << b << std::endl;
}

auto main() -> int { nop(); }
