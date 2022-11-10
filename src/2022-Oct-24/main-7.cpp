auto factorialRec(int n) -> int {
    if (n >= 1) {
        return n * factorialRec(n - 1);
    } else {
        return 1;
    }
}

auto main() -> int { return 0; }
