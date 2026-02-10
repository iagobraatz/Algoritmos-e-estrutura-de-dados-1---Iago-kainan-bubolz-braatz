#include <stdlib.h>

void backtracking(int inicio, int n, int k, int* atual, int tamanho,
                  int*** resultado, int* returnSize, int** returnColumnSizes, int* capacidade) {
    if (tamanho == k) {
        if (*returnSize >= *capacidade) {
            *capacidade *= 2;
            *resultado = (int**)realloc(*resultado, (*capacidade) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*capacidade) * sizeof(int));
        }

        (*resultado)[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++)
            (*resultado)[*returnSize][i] = atual[i];

        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = inicio; i <= n; i++) {
        atual[tamanho] = i;
        backtracking(i + 1, n, k, atual, tamanho + 1,
                     resultado, returnSize, returnColumnSizes, capacidade);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacidade = 1000;

    int** resultado = (int**)malloc(capacidade * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacidade * sizeof(int));

    int* atual = (int*)malloc(k * sizeof(int));

    backtracking(1, n, k, atual, 0,
                 &resultado, returnSize, returnColumnSizes, &capacidade);

    free(atual);
    return resultado;
}
