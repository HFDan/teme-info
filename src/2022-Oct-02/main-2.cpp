auto sumafactcif(int num) -> int {
    int suma = 0;
    do {
        const int cifra = num % 10;

        int fact = 1;
        for (int i = 1; i <= cifra; i++) {
            fact *= i;
        }

        suma += fact;

        num /= 10;
    } while (num != 0);

    return suma;
}
auto main() -> int { return 0; }
