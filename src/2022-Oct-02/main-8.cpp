#include <cppminimal>

auto nr_sa(int** a, int n, int m) -> int {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // a[rand][col]
            int numar = a[i][j];

            // calculam
            std::byte flags{0b00000000};

            // format:
            // 0b<cel mai mare de pe coloana><cel mai mic de pe coloana><cel mai mare de pe rand><cel mai mic de pe
            // rand>

            // Intai vedem pe rand
            int colmax = INT_MIN;
            int colmin = INT_MAX;
            for (int coloana = 0; coloana < m; coloana++) {
                if (a[i][coloana] > colmax) colmax = a[i][coloana];

                if (a[i][coloana] < colmin) colmin = a[i][coloana];
            }

            if (numar == colmin) flags |= std::byte{0b01000000};

            if (numar == colmax) flags |= std::byte{0b10000000};

            int randmax = INT_MIN;
            int randmin = INT_MAX;
            for (int rand = 0; rand < n; rand++) {
                if (a[rand][j] > randmax) randmax = a[rand][j];

                if (a[rand][j] < randmin) randmin = a[rand][j];
            }

            if (numar == randmin) flags |= std::byte{0b00010000};

            if (numar == randmax) flags |= std::byte{0b00100000};

            if (flags == std::byte{0b10010000} || flags == std::byte{0b01100000}) cont++;
        }
    }

    return cont;
}
auto main() -> int { return 0; }
