#include <cppminimal>

auto multiplu(std::span<int> a, size_t n, int k) -> int {
    int cont = 0;
    for (size_t i = 0; i < n; i++) {
        if ((a[i] % k == 0) && (a[i] % 10 == k)) cont++;
    }

    return cont;
}
auto main() -> int { return 0; }
