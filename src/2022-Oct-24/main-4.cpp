auto cmmdcRec(int x, int y) -> int {
    if (x == 0 || y == 0) return 0;

    if (x == y) return x;

    if (x > y)
        return cmmdcRec(x - y, y);
    else
        return cmmdcRec(x, y - x);
}

auto main() -> int { return 0; }
