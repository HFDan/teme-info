#include <cppminimal>

int ExistaImpareRec(int n) {
    if ((n % 10) % 2 != 0) return 1;
    if (n == 0) return 0;
    return 0 + ExistaImpareRec(n / 10);
}

auto main() -> int {
    std::cout << ExistaImpareRec(2232);
    return 0;
}
