#include <cppminimal>

auto sumaVector(std::span<int> vec, size_t left, size_t right) -> int {
    if (left != right) {
        size_t mid = std::midpoint(left, right);
        int first = sumaVector(vec, left, mid);
        int second = sumaVector(vec, mid + 1, right);

        return first + second;
    }

    return vec[left];
}

auto multVector(std::span<int> vec, size_t left, size_t right) -> int {
    if (left != right) {
        size_t mid = std::midpoint(left, right);
        int first = multVector(vec, left, mid);
        int second = multVector(vec, mid + 1, right);

        return first * second;
    }

    return vec[left];
}

auto main() -> int { return 0; }
