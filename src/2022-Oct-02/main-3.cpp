auto lmao(int n, int k) -> int {
    int numarul = 0;

    // Dupa ce inversam, putem reconstrui numarul
    {
        int ogl = 0;
        while (n) {
            ogl = ogl * 10 + n % 10;

            n /= 10;
        }

        n = ogl;
    }

    for (int i = 0; i < k; i++, n /= 10) {
        numarul = numarul * 10 + n % 10;
    }

    return numarul;
}
auto main() -> int { return 0; }
