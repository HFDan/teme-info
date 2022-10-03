int lmao(int num) {
    int rt = 0;

    do {
        rt += num % 10;
        num /= 10;
    } while (num != 0);

    return rt;
}int main() {return 0;}
