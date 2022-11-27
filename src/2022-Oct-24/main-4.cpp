auto cmmdcRec(int num1, int num2) -> int {
    if (num1 == 0 || num2 == 0) return 0;

    if (num1 == num2) return num1;

    if (num1 > num2)
        return cmmdcRec(num1 - num2, num2);
    else
        return cmmdcRec(num1, num2 - num1);
}

auto main() -> int { return 0; }
