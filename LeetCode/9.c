bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    int invertido = 0;

    while (x > 0) {
        invertido = invertido * 10 + (x % 10);
        x /= 10;
    }

    return original == invertido;
}
