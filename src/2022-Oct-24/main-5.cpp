#include <concepts>
#include <cstdint>
#include <cstddef>

// I love c++20
template <typename T>
concept isStdContainerCompatible = (std::integral<typename T::value_type> || std::floating_point<typename T::value_type>) && requires (T a) {
    a.begin();
    a.end();
    a.size();
};

template <typename T>
requires isStdContainerCompatible<T>
typename T::value_type sumaElementeVectori(T vec) {
    typename T::value_type runningTotal = 0;
    for (auto it : vec) {
        runningTotal += it;
    }

    return runningTotal;
}

template <typename T>
requires (std::integral<T> || std::floating_point<T> 
// Check for + operator
|| requires (T a) {a + a;})
T sumaElementeVectori(T* vec, size_t sz) {
    T runningTotal = 0;
    for (size_t i = 0; i < sz; i++)
        runningTotal += vec[i];

    return runningTotal;
}

int main() {
    return 0;
}
