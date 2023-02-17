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

constexpr auto cmmmc(int a, int b) {
    return a * b / cmmdc(a, b);
}

constexpr void simpl(fract& fr) {
    auto divizor = cmmdc(fr.x, fr.y);
    fr.x /= divizor;
    fr.y /= divizor;
}

auto main(int argc, char** argv) -> int {

    fract fr1;
    fract fr2;
    std::cin >> fr1 >> fr2;
    
    auto amp_to = cmmmc(fr1.y, fr2.y);
    fr1.x *= (amp_to/fr1.x);
    fr1.y *= (amp_to/fr1.y);

    fr2.x *= (amp_to/fr2.x);
    fr2.y *= (amp_to/fr2.y);
    
    std::cout << fr1 << std::endl << fr2 << std::endl;
    return 0;
}