auto SumaCifreRec(int n) -> int {
    if (n < 10) {
        return n % 10;
    } else {
        return (n % 10) + SumaCifreRec(n / 10);
    }
}

auto main() -> int { return 0; }
