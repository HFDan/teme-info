#include <cppminimal>

// I love c++20
template <typename T>
concept isStdContainerCompatible =
    (std::integral<typename T::value_type> || std::floating_point<typename T::value_type>)&&requires(T a) {
    a.begin();
    a.end();
    a.size();
};

template <typename T>
requires isStdContainerCompatible<T>
auto sumaElementeVectori(T vec) -> typename T::value_type {
    typename T::value_type runningTotal = 0;
    for (auto it : vec) {
        runningTotal += it;
    }

    return runningTotal;
}

template <typename T>
requires(std::integral<T> || std::floating_point<T> || requires(T a) {
    a + a;
}) auto sumaElementeVectori(std::span<T> vec) -> T {
    T runningTotal = 0;
    for (size_t i = 0; i < vec.size(); i++) runningTotal += vec[i];

    return runningTotal;
}

template <typename T>
requires(std::integral<T> || std::floating_point<T> || requires(T a) {
    a + a;
}) auto sumaElemVectoriRec(T* vec, size_t sz) -> T {
    if (sz == 1) {
        return vec[sz - 1];
    } else {
        return vec[sz - 1] + sumaElemVectoriRec(vec, sz - 1);
    }
}

auto main() -> int { return 0; }
