int multiplu(int a[], int n, int k) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] % k == 0) && (a[i] % 10 == k))
            cont++; 
    }

    return cont;
}int main() {return 0;}
