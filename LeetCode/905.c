/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {

    int* resultado = (int*) malloc(numsSize * sizeof(int));
    int indice = 0;
    int i;

    // Primeiro coloca os pares
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            resultado[indice] = nums[i];
            indice++;
        }
    }

    // Depois coloca os ímpares
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 != 0) {
            resultado[indice] = nums[i];
            indice++;
        }
    }

    *returnSize = numsSize;
    return resultado;
}
