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
    stream << fr.real << '+' << fr.img << 'i';
    return stream;
}

auto operator*(const complex& c1, const complex& c2) {
    return complex {
        .real = (c1.real * c2.real) - (c1.img * c2.img),
        .img = (c1.real * c2.img) + (c1.img * c2.real)
    };
}

auto main(int argc, char** argv) -> int {
    complex c1;
    complex c2;
    std::cin >> c1 >> c2;
    
    std::cout << c1 * c2 << std::endl;
    return 0;
}

