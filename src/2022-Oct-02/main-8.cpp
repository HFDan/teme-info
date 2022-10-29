#include <cppminimal>

int nr_sa(int** a, int n, int m) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // a[rand][col]
            int numar = a[i][j];

            // calculam
            unsigned char flags = 0b00000000;

            // format:
            // 0b<cel mai mare de pe coloana><cel mai mic de pe coloana><cel mai mare de pe rand><cel mai mic de pe rand>

            // Intai vedem pe rand
            int colmax = INT_MIN;
            int colmin = INT_MAX;
            for (int coloana = 0; coloana < m; coloana++) {
                if (a[i][coloana] > colmax)
                    colmax = a[i][coloana];
                
                if (a[i][coloana] < colmin)
                    colmin = a[i][coloana];
            }

            if (numar == colmin)
                flags |= 0b01000000;
            
            if (numar == colmax)
                flags |= 0b10000000;

            
            int randmax = INT_MIN;
            int randmin = INT_MAX;
            for (int rand = 0; rand < n; rand++) {
                if (a[rand][j] > randmax)
                    randmax = a[rand][j];
                
                if (a[rand][j] < randmin)
                    randmin = a[rand][j];
            }

            if (numar == randmin)
                flags |= 0b00010000;

            if (numar == randmax)
                flags |= 0b00100000;

            if (flags == 0b10010000 || flags == 0b01100000)
                cont++;

        }
    }

    return cont;
}int main() {return 0;}
