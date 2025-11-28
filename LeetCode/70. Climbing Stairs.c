int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2, temp;
    for (int i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
