int nrCifreDiv3(int n, int cifreDiv = 0) {
    if (n) {
        if ((n%10) % 3 == 0) {
            return nrCifreDiv3(n / 10, cifreDiv + 1);
        } else {
            return nrCifreDiv3(n / 10, cifreDiv);
        }
    } else {
        return cifreDiv;
    }
}

int main() {
    return 0;
}
