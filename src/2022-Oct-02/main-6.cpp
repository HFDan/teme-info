#include <cppminimal>

auto interval(std::span<int> arr, typename std::span<int>::size_type n) -> int {
    int cont = 0;
    const auto primu = arr[0];
    const auto doilea = arr[n - 1];

    for (decltype(n) i = 0; i < n; i++) {
        const auto num = arr[i];
        if (num >= primu && num <= doilea) cont++;
    }

    return cont;
}
auto main() -> int { return 0; }
