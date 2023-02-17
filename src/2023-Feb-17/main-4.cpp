#include <iostream>
#include <cmath>

struct complex {
    double real;
    double img;
};

auto& operator>>(std::istream& stream, complex& fr){
    stream >> fr.real >> fr.img;
    return stream;
} 

auto& operator<<(std::ostream& stream, const complex& fr) {
    stream << fr.real << '*' << fr.img << 'i';
    return stream;
}

auto mod(const complex& cmp) {
    return std::sqrt(std::pow(cmp.real, 2)+std::pow(cmp.img, 2));
}

auto main(int argc, char** argv) -> int {
    complex c;
    std::cin >> c;
    std::cout << mod(c) << std::endl;

    return 0;
}

