auto SumaCifreRec(int n) -> int {
    if (n < 10) return (n % 10) % 2 == 0 ? 1 : -1;

    if ((n % 10) % 2 == 0) {
        return 1 + SumaCifreRec(n / 10);
    } else {
        return -1 + SumaCifreRec(n / 10);
    }
}

auto main() -> int { return 0; }
