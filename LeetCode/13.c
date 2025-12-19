int valor(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    return 1000;
}

int romanToInt(char* s) {
    int total = 0;
    int atual = 0;
    int proximo = 0;

    for (int i = 0; s[i]; i++) {
        atual = valor(s[i]);
        proximo = s[i + 1] ? valor(s[i + 1]) : 0;

        if (atual < proximo)
            total -= atual;
        else
            total += atual;
    }

    return total;
}
