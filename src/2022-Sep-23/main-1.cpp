/*
Prin înjumătățirea unui număr natural se înțelege înlocuirea fiecărei cifre
pare cu jumătatea ei. De exemplu,
prin înjumătățirea numărului 5622 se obține numărul 5311.
Fișierul atestat.in conține pe prima linie un număr natural n (2≤n≤100), iar pe a doua linie, un șir
de n numere naturale cu cel mult 9 cifre fiecare.
Se consideră subprogramele:

verif care are un singur parametru x (număr natural cu maxim 9 cifre) și returnează valoarea 1
dacă toate cifrele numărului x sunt pare sau valoarea 0, în caz contrar.

modif care are ca unic parametru numărul natural x. Subprogramul înjumătățește valoarea lui x
(conform definiției de mai sus) și furnizează numărul modificat prin intermediul aceluiași parametru.

Cerințe:
a. Să se scrie definiția completă a subprogramului verif;
b. Să se scrie definiția completă a subprogramului modif;
c. Să se scrie un program care citește din fișierul atestat.in numărul n și cele n elemente ale
tabloului unidimensional v și, folosind apeluri utile ale subprogramelor verif și modif, determină
înjumătățirea (conform definiției de mai sus) a elementelor tabloului care au toate cifrele pare.
Programul scrie pe prima linie a fișierului atestat.out elementele tabloului modificat.
Elementele tabloului care conțin cel puțin o cifră impară nu se modifică
*/

#include <cppminimal>

bool verif(int num) {
    while (num != 0) {
        if ((num % 10) % 2 != 0) return false;

        num /= 10;
    }

    return true;
}

// Don't know why, but i changed random stuff and now it works
// Doing this shit is considered "bad coding practice"
// But if you do it fast enough, it's "machine learning"
// And it pays 10x your current salary
void modif(int& x) {
    int numaruPeDos = 0;

    while (x != 0) {
        uint8_t cifra = x % 10;

        if (cifra % 2 == 0) cifra /= 2;

        numaruPeDos += cifra;
        numaruPeDos *= 10;

        x /= 10;
    }

    numaruPeDos /= 10;

    {
        int ogl = 0;
        int cpcp = numaruPeDos;
        while (cpcp != 0) {
            ogl = ogl * 10 + cpcp % 10;
            cpcp /= 10;
        }

        numaruPeDos = ogl;
    }

    x = numaruPeDos;
}

int main(int argc, char** argv) {
    std::ifstream file("atestat.in");
    std::ofstream out("atestat.out");
    long sz;
    file >> sz;

    for (long i = 0; i < sz; i++) {
        int nr;
        file >> nr;

        if (verif(nr)) modif(nr);

        out << nr << std::endl;
    }

    return EXIT_SUCCESS;
}