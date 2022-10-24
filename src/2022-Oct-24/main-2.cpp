int SumaCifreRec(int n, int pare = 0, int impare = 0) {
    if (n) {
        if ((n % 10) % 2 == 0) {
            return SumaCifreRec(n/10, pare + 1, impare);
        } else {
            return SumaCifreRec(n/10, pare, impare + 1);
        }
    } else {
        return pare - impare;
    }
}

int main() {
    return 0;
}
