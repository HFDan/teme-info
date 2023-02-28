#include <iostream>
#include <cmath>

struct point {
    double x;
    double y;
};

enum class TriangleTypes {
    right,
    isosceles,
    equilateral,
    other
};

auto& operator<<(std::ostream& stream, const TriangleTypes type) {
    
    switch (type) {
        using enum TriangleTypes;
        case equilateral:
            stream << "Echilateral";
            break;
        
        case isosceles:
            stream << "Isoscel";
            break;

        case right:
            stream << "Dreptunghic";
            break;

        case other:
            stream << "Oarecare";
            break;
    }

    return stream;
}

auto& operator>>(std::istream& stream, point& pt) {
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

auto coliniar(const point& p1, const point& p2, const point& p3) {
    auto fr1 = (p3.y - p1.y) / (p2.y - p1.y);
    auto fr2 = (p3.x - p1.x) / (p2.x - p1.x);
    return fr1 == fr2;
}

auto determineTriangleType(const point& p1, const point& p2, const point& p3) {
    if (dist(p1, p2) == dist(p1, p3))
        return TriangleTypes::isosceles;
    
    if (dist(p2, p1) == dist(p2, p3))
        return TriangleTypes::isosceles;

    if (dist(p3, p1) == dist(p3, p2))
        return TriangleTypes::isosceles;

    if (dist(p1, p2) == dist(p1, p3) && dist(p1, p2) == dist(p2, p3))
        return TriangleTypes::equilateral;

    return TriangleTypes::other;
}

auto main(int argc, char** argv) -> int {
    point p1;
    point p2;
    point p3;
    std::cin >> p1 >> p2 >> p3;
    
    // 3 puncte pot forma un triunghi doar daca NU sunt coliniare!
    std::cout << "Poate forma triunghi?: " << (!coliniar(p1, p2, p3) ? "Da" : "Nu") << std::endl;
    
    std::cout << determineTriangleType(p1, p2, p3) << std::endl;
    return 0;
}