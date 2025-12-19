bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int metade = 0;

    while (x > metade) {
        metade = metade * 10 + x % 10;
        x /= 10;
    }

    return x == metade || x == metade / 10;
}
