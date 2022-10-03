int sumafactcif(int num) {
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
}int main() {return 0;}
