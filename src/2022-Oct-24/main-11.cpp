auto cmmdc(int num1, int num2) -> int {
    if (num1 == num2)
        return num1;
    else if (num1 > num2)
        return cmmdc(num1 - num2, num2);
    else
        return cmmdc(num1, num2 - num1);
}

auto main() -> int { return 0; }
