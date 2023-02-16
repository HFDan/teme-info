// se citesc n pct sa se afis pe ecran dist maxima fata de origine si nr de pct aflate la dist maxima

#include <iostream>
#include <cmath>
#include <type_traits>

template <typename T = float>
struct point {
    static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>, "Underlying type of point must be a floating point or integral type");
    
    using value_type = T;

    T x{static_cast<T>(0)};
    T y{static_cast<T>(0)};
};

template <typename T>
auto getDistanceBetweenPoints(const point<T>& p1, const point<T>& p2) -> T {
    const auto first_exp = pow(static_cast<double>(p2.x - p1.x), 2);
    const auto second_exp = pow(static_cast<double>(p2.y - p1.y), 2);
    return static_cast<T>(sqrt(first_exp + second_exp));
}

auto main(int argc, char** argv) -> int {

    std::size_t n;
    std::cin >> n;

    point<int> pts[100];
    for (std::size_t i = 0; i < n; i++) {
        std::cin >> pts[i].x >> pts[i].y;
    }
    
    std::size_t max_dist = 0;
    for (std::size_t i = 0; i < n; i++) {
        const auto dist = getDistanceBetweenPoints({0, 0}, pts[i]);
        if (dist > max_dist)
            max_dist = dist;
    }
    
    std::size_t cnt = 0;
    for (std::size_t i = 0; i < n; i++) {
        const auto dist = getDistanceBetweenPoints({0, 0}, pts[i]);
        if (dist == max_dist)
            cnt++;
    }
    
    std::cout << max_dist << std::endl << cnt << std::endl;

    return 0;
}