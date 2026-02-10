#include <stdbool.h>

int somaQuadrados(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

bool isHappy(int n) {
    int lento = n;
    int rapido = n;

    do {
        lento = somaQuadrados(lento);
        rapido = somaQuadrados(somaQuadrados(rapido));
    } while (lento != rapido);

    return lento == 1;
}
