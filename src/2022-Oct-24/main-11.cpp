auto cmmdc(int a, int b) -> int {
    if (a == b)
        return a;
    else if (a > b)
        return cmmdc(a - b, b);
    else
        return cmmdc(a, b - a);
}

auto main() -> int { return 0; }
