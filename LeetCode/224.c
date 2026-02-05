#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    long long resultado = 0;
    long long numero = 0;
    int sinal = 1;
    int tamanho = 0;

    while (s[tamanho] != '\0')
        tamanho++;

    long long* pilha = (long long*)malloc(sizeof(long long) * tamanho);
    int topo = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            numero = numero * 10 + (s[i] - '0');
        } else if (s[i] == '+') {
            resultado += sinal * numero;
            numero = 0;
            sinal = 1;
        } else if (s[i] == '-') {
            resultado += sinal * numero;
            numero = 0;
            sinal = -1;
        } else if (s[i] == '(') {
            pilha[++topo] = resultado;
            pilha[++topo] = sinal;
            resultado = 0;
            sinal = 1;
        } else if (s[i] == ')') {
            resultado += sinal * numero;
            numero = 0;
            resultado *= pilha[topo--];
            resultado += pilha[topo--];
        }
    }

    resultado += sinal * numero;
    free(pilha);

    return (int)resultado;
}
