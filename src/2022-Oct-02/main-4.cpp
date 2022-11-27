#include <cppminimal>

auto lmao(size_t num) -> int {
    std::array<int, 10> frec{};

    while (num != 0) {
        frec[num % 10]++;

        num /= 10;
    }

    int rec = 0;

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < frec[i]; j++) {
            rec = rec * 10 + i;
        }
    }

    return rec;
}
auto main() -> int { return 0; }
