int ExistaImpareRec(int n) {
    if ((n % 10) % 2 == 0)
        return 1 + ExistaImpareRec(n/10);

    return 1;

}

int main() {
    return 0;
}
