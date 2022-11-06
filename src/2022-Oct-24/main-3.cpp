int nrCifreDiv3(int n) {
    if (n < 10) return (n % 10) % 3 == 0 ? 1 : 0;

    if ((n % 10) % 3 == 0) {
        return 1 + nrCifreDiv3(n / 10);
    } else {
        return 0 + nrCifreDiv3(n / 10);
    }
}

int main() { return 0; }
