auto lmao(int num) -> int {
    int ret = 0;

    do {
        ret += num % 10;
        num /= 10;
    } while (num != 0);

    return ret;
}
auto main() -> int { return 0; }
