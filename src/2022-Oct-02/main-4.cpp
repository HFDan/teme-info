int lmao(int num) {
    int frec[10] = {0};

    while (num) {
        frec[num % 10]++;

        num /= 10;
    }

    int rec = 0;

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < frec[i]; j++) {
            rec = rec * 10 + i;
        }
    } 

    return rec;
}