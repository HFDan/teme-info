#include <cppminimal>

void citireVecRec(std::span<int> vec, size_t idx, size_t size) {
    if (idx == size - 1) {
        std::cin >> vec[idx];
    } else {
        std::cin >> vec[idx];
        return citireVecRec(vec, idx + 1, size);
    }
}

auto main() -> int { return 0; }
