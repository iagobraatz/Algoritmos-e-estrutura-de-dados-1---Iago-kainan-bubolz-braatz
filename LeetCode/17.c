/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

char* mapa[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void gerar(char* digits, int pos, char* atual, char** lista, int* tamanho) {
    if (!digits[pos]) {
        lista[*tamanho] = malloc(strlen(atual) + 1);
        strcpy(lista[*tamanho], atual);
        (*tamanho)++;
        return;
    }

    char* letras = mapa[digits[pos] - '0'];
    for (int i = 0; letras[i]; i++) {
        atual[pos] = letras[i];
        gerar(digits, pos + 1, atual, lista, tamanho);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (!digits[0]) return NULL;

    int total = 1;
    for (int i = 0; digits[i]; i++)
        total *= strlen(mapa[digits[i] - '0']);

    char** lista = malloc(total * sizeof(char*));
    char atual[5] = {0};

    gerar(digits, 0, atual, lista, returnSize);

    return lista;
}
