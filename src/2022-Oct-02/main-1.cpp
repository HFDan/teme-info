auto lmao(int num) -> int {
    int rt = 0;

    do {
        rt += num % 10;
        num /= 10;
    } while (num != 0);

    return rt;
}
auto main() -> int { return 0; }
