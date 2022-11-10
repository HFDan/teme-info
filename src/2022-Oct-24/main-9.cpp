#include <cppminimal>

auto max(int vec[], int left, int right) -> int {
    if (left == right) {
        return vec[left];
    } else {
        int m = std::midpoint(left, right);
        int a = max(vec, left, m);
        int b = max(vec, m + 1, right);

        if (a > b)
            return a;
        else
            return b;
    }
}

auto min(int vec[], int left, int right) -> int {
    if (left == right) {
        return vec[left];
    } else {
        int m = std::midpoint(left, right);
        int a = min(vec, left, m);
        int b = min(vec, m + 1, right);

        if (a < b)
            return a;
        else
            return b;
    }
}

auto main() -> int {
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << min(vec, 0, 9);
    return 0;
}
