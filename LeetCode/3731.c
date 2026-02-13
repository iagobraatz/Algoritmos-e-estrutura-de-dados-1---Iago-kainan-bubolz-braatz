/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {

    int i;
    int menor = nums[0];
    int maior = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (nums[i] < menor) {
            menor = nums[i];
        }
        if (nums[i] > maior) {
            maior = nums[i];
        }
    }

    int tamanho_intervalo = maior - menor + 1;

    int* marcacao = (int*) calloc(tamanho_intervalo, sizeof(int));

    for (i = 0; i < numsSize; i++) {
        marcacao[nums[i] - menor] = 1;
    }

    int* resultado = (int*) malloc(tamanho_intervalo * sizeof(int));
    int indice = 0;

    for (i = 0; i < tamanho_intervalo; i++) {
        if (marcacao[i] == 0) {
            resultado[indice] = menor + i;
            indice++;
        }
    }

    free(marcacao);

    *returnSize = indice;
    return resultado;
}
