int count(int a[], int n) {
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma += a[i];
    }
    ma /= n;

    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= ma) 
            cont++;
    }

    return cont;
}int main() {return 0;}
