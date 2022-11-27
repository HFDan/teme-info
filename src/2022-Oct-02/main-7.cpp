#include <cppminimal>

auto count(std::span<int> a, size_t n) -> int {
    int mean = 0;
    for (size_t i = 0; i < n; i++) {
        mean += a[i];
    }
    mean /= n;

    int cont = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] >= mean) cont++;
    }

    return cont;
}
auto main() -> int { return 0; }
