#include <cppminimal>

// Problema asta e oribila.
// Vreau sa mor

static int mat[101][101];
static int n;

typedef std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>, std::pair<int, int>> kys_t;

void printMat() { 
    for (int rand = 1; rand <= n; rand++) {
        for (int coloana = 1; coloana <= n; coloana++)
            std::cout << mat[rand][coloana] << " "; 

        std::cout << std::endl;
    }
}

kys_t findPos() {
    // Chestia asta chiar suge
    auto maxN = [&](int& imax, int& jmax) -> void {
        int max = 0;
        for(int i = 1; i <= n / 2; i++)
            for(int j = i + 1; j < n + 1 - i; j++)
                if( mat[i][j] > max ) { max=mat[i][j]; imax=i; jmax=j; }
    };

    auto maxS = [&](int& imax, int& jmax) -> void {
        int max = 0;
        for(int i = n / 2 + 1; i <= n; i++)
            for(int j= n + 1 - i + 1; j < i; j++)
                if( mat[i][j] > max ) { max=mat[i][j]; imax=i; jmax=j; }
    };

    auto maxV = [&](int& imax, int& jmax) -> void {
        int max = 0;
        for(int i = 2; i <= n - 1; i++)
            for(int j = 1; j < std::min(i,n+1-i); j++)
                if( mat[i][j] > max ) { max=mat[i][j]; imax=i; jmax=j; }
    };

    auto maxE = [&](int& imax, int& jmax) -> void {
        int max = 0;
        for(int i = 2; i <= n - 1; i++)
            for(int j = std::max(i,n+1-i) + 1; j <= n; j++)
                if( mat[i][j] > max ) { max=mat[i][j]; imax=i; jmax=j; }
    };

    std::pair<int, int> N, S, V, E;
    maxN(N.first, N.second);
    maxS(S.first, S.second);
    maxE(E.first, E.second);
    maxV(V.first, V.second);

    return {N, E, S, V};
}

inline void interschimbare2elemente(const int& rand1, const int& col1, const int& rand2, const int& col2) {
    std::swap(mat[rand1][col1], mat[rand2][col2]);
}

inline void interschimbareConformCerintei() {
    auto[coordN, coordE, coordS, coordV] = findPos();

    interschimbare2elemente(coordN.first, coordN.second, coordE.first, coordE.second);
    interschimbare2elemente(coordV.first, coordV.second, coordS.first, coordS.second);
    interschimbare2elemente(coordN.first, coordN.second, coordS.first, coordS.second);
}

int main(int argc, char** argv) {

    // Citire e tehnic functie
    auto citire = [&]() -> void {
        std::cin >> n;
        for (int rand = 1; rand <= n; rand++) {
            for (int coloana = 1; coloana <= n; coloana++)
                std::cin >> mat[rand][coloana]; 
        }
    };

    citire();
    interschimbareConformCerintei();
    printMat();

}
