#include <iostream>

struct fract {
    int x;
    int y;
};

auto& operator>>(std::istream& stream, fract& fr){
    stream >> fr.x >> fr.y;
    return stream;
}

auto& operator<<(std::ostream& stream, const fract& fr) {
    stream << fr.x << '/' << fr.y;
    return stream;
}

constexpr auto cmmdc(int a, int b) {

    while (b != 0) {
        const int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

auto main(int argc, char** argv) -> int {

    fract fr;
    std::cin >> fr;

    auto divizor = cmmdc(fr.x, fr.y);
    fr.x /= divizor;
    fr.y /= divizor;
    
    std::cout << fr << std::endl;

    return 0;
}