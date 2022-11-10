#include <cppminimal>

auto interval(std::span<int> a, int n) -> int {
    int cont = 0;
    const int primu = a[0];
    const int doilea = a[n - 1];

    for (int i = 0; i < n; i++) {
        const int nr = a[i];
        if (nr >= primu && nr <= doilea) cont++;
    }

    return cont;
}
auto main() -> int { return 0; }
