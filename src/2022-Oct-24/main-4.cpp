int cmmdcRec(int x, int y) {
    if (x == 0 || y == 0) return 0;

    if (x == y) return x;

    if (x > y)
        return cmmdcRec(x - y, y);
    else
        return cmmdcRec(x, y - x);
}

int main() { return 0; }
