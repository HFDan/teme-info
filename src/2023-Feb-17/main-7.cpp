#include <iostream>
#include <cmath>

struct point {
    double x;
    double y;
};

auto& operator>>(std::istream& stream, point& pt){
    stream >> pt.x >> pt.y;
    return stream;
} 

auto& operator<<(std::ostream& stream, const point& pt) {
    stream << '(' << pt.x << ", " << pt.y << ')';
    return stream;
}

auto dist(const point& p1, const point& p2) {
    const auto first_exp = pow(p2.x - p1.x, 2);
    const auto second_exp = pow(p2.y - p1.y, 2);
    return sqrt(first_exp + second_exp);
}

auto main(int argc, char** argv) -> int {
    point p1;
    point p2;
    point p3;
    std::cin >> p1 >> p2 >> p3;
    
    std::cout << "P1 <-> P2" << dist(p1, p2) << std::endl;
    std::cout << "P1 <-> P3" << dist(p1, p3) << std::endl;
    std::cout << "P2 <-> P3" << dist(p2, p3) << std::endl;
    return 0;
}