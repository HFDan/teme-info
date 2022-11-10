#include <cppminimal>

void citireVecRec(std::span<int> vec, int idx, int sz) {
    if (idx == sz - 1) {
        std::cin >> vec[idx];
    } else {
        std::cin >> vec[idx];
        return citireVecRec(vec, idx + 1, sz);
    }
}

auto main() -> int { return 0; }
