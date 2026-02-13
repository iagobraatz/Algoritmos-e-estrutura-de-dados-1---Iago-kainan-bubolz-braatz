/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int* resultado = (int*) malloc(1000 * sizeof(int));
    int marcacao[1001] = {0};
    int ja_adicionado[1001] = {0};
    int tamanho = 0;
    int i;

    for (i = 0; i < nums1Size; i++) {
        marcacao[nums1[i]] = 1;
    }

    for (i = 0; i < nums2Size; i++) {
        int valor = nums2[i];

        if (marcacao[valor] == 1 && ja_adicionado[valor] == 0) {
            resultado[tamanho] = valor;
            tamanho++;
            ja_adicionado[valor] = 1;
        }
    }

    *returnSize = tamanho;

    return resultado;
}
