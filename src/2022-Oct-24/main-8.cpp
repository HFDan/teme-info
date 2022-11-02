int SumaCifreRec(int n) {
    if (n < 10) {
        return n % 10;
    } else {
        return (n % 10) + SumaCifreRec(n / 10);
    }
}

int main() {
    return 0;
}
