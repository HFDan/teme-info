//o struct care memoreaza coord unui pct , se citesc de la tastatura coordonatele a n pct
// sa se afiseze pe ecran cate pct fac parte din cadranul 1
#include <iostream>
#include <type_traits>

// This is unused. The exercise does not require this.
template <typename T = float>
struct point {
    static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>, "Underlying type of point must be a floating point or integral type");

    using value_type = T;
    
    T x{static_cast<T>(0)};
    T y{static_cast<T>(0)};
};

auto main(int argc, char** argv) -> int {

    std::size_t n;
    std::cin >> n;

    std::size_t ctr = 0;
    for (; n >= 0; n--) {
        float x, y;
        std::cin >> x >> y;

        if (x >= 0.0f && y >= 0.0f)
            ctr++; 
    }

    std::cout << ctr << std::endl; 

    return 0;
}