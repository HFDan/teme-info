auto count(int a[], int n) -> int {
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma += a[i];
    }
    ma /= n;

    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= ma) cont++;
    }

    return cont;
}
auto main() -> int { return 0; }
