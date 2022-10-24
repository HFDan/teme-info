int SumaCifreRec(int n, int suma = 0) {
    if (n) {
        return SumaCifreRec(n / 10, suma + (n % 10));
    } else {
        return suma;
    }
}

int main() {
    return 0;
}
