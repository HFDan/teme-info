#include <cppminimal>

auto max(std::span<int> vec, int left, int right) -> int {
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

auto min(std::span<int> vec, size_t left, size_t right) -> int {
    if (left == right) {
        return vec[left];
    } else {
        size_t mid = std::midpoint(left, right);
        int first = min(vec, left, mid);
        int second = min(vec, mid + 1, right);

        if (first < second)
            return first;
        else
            return second;
    }
}

auto main() -> int {
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << min(vec, 0, 9);
    return 0;
}
