int factorialRec(int n) {
    if (n >= 1) {
        return n * factorialRec(n - 1);
    } else {
        return 1;
    }
}

int main() { return 0; }
