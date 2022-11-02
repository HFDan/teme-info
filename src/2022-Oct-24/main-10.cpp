#include <cppminimal>

int sumaVector(int vec[], int left, int right) {

    if (left != right) {
        int m = std::midpoint(left, right);
        int a = sumaVector(vec, left, m);
        int b = sumaVector(vec, m + 1, right);

        return a + b;
    }

    return vec[left];
}

int multVector(int vec[], int left, int right) {

    if (left != right) {
        int m = std::midpoint(left, right);
        int a = multVector(vec, left, m);
        int b = multVector(vec, m + 1, right);

        return a * b;
    }

    return vec[left];
}

int main() {
    return 0;
}
