/*
Fișierul atestat.in conține pe prima linie un număr natural n, 2≤n≤100 și pe a doua linie n numere
naturale cu cel puțin 2 și cel mult 6 cifre, separate printr-un spațiu.
Se consideră subprogramele:


inversareCifre cu un parametru x, prin intermediul căruia primește un număr natural format
din cel mult 6 cifre. Subprogramul modifică valoarea lui x, inversând ordinea cifrelor lui, cu excepția
primei cifre care rămâne în aceeași poziție. De exemplu, pentru valoarea 21754 a parametrului x,
în urma executării subprogramului, valoarea furnizată prin parametrul x va fi 24571.


nrDivizori cu un parametru x, prin intermediul căruia primește un număr natural nenul, format
din cel mult 6 cifre. Subprogramul returnează numărul divizorilor parametrului x.


Cerințe:
a. Să se scrie definiția completă a subprogramului inversareCifre;
b. Să se scrie definiția completă a subprogramului nrDivizori;
c. Să se scrie un program care citește din fișierul atestat.in numărul n și cele n numere naturale,
iar apoi, folosind apeluri utile ale subprogramelor inversareCifre și nrDivizori, modifică
fiecare număr din șir care are mai mult de 4 divizori, inversând ordinea tuturor cifrelor lui, cu
excepția primei cifre care rămâne în aceeași poziție și scrie în fișierul atestat.out, pe prima
linie, toate numerele din șirul modificat. Dacă nu există numere cu mai mult de 4 divizori se va
scrie în fișier, mesajul "nu au fost facute modificari"
*/

#include <cppminimal>

// I am so tempted to use strings, so heres a toggle
void inversareCifre(int& x, bool useStrings = false) {
    if (useStrings) {
        std::string str = std::to_string(x);
        std::reverse(str.begin() + 1, str.end());
        x = std::stoi(str);
    } else {
        // We can do it the *math* way (yuck, cringe, 🤮)
        // Or we can do it the *fundular entertainment* way (Based, max0r reference)

        int digits[6] = {0};  // Yes, this works, but only with 0, nothing else.
        int iteratorBazat;    // We will need this later
        for (iteratorBazat = 0; x > 0; iteratorBazat++) {
            digits[iteratorBazat] = x % 10;
            x /= 10;
        }

        // This can be made "more efficient", but i dont have the time nor the motivation to do it.
        // Just be glad it works, and never touch it again.
        // This code gives me a headache...

        // We reverse the digits...
        for (int i = 0, j = iteratorBazat - 1; i <= j; j--, i++) std::swap(digits[i], digits[j]);

        // We reverse what we need...
        for (int i = 1, j = iteratorBazat - 1; i <= j; j--, i++) std::swap(digits[i], digits[j]);

        // Rebuild the number
        x = 0;
        for (int i = 0; i < iteratorBazat; i++) {
            x = x * 10 + digits[i];
        }
    }
}

constexpr auto nrDivizori(const int& x) -> int {
    int div = 0;

    for (int i = 1; i <= x; i++)
        if (x % i == 0) div++;

    return div;
}

auto main(int argc, char** argv) -> int {
    freopen("atestat.in", "r", stdin);
    freopen("atestat.out", "w", stdout);

    int n;
    std::cin >> n;

    auto* const arr = new int[n];

    {
        static int TimesFunctionWasCalled = 0;
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;

            if (nrDivizori(num) > 4) {
                inversareCifre(num);
                TimesFunctionWasCalled++;
            }
            arr[i] = num;
        }

        if (!TimesFunctionWasCalled) {
            std::cout << "Nu au fost facute modificari" << std::endl;
            return EXIT_SUCCESS;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;
    return EXIT_SUCCESS;
}