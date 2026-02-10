#include <stdlib.h>

int comparar(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), comparar);

    int capacidade = 1000;
    int** resultado = (int**)malloc(capacidade * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacidade * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int esquerda = i + 1;
        int direita = numsSize - 1;

        while (esquerda < direita) {
            long soma = (long)nums[i] + nums[esquerda] + nums[direita];

            if (soma == 0) {
                if (*returnSize >= capacidade) {
                    capacidade *= 2;
                    resultado = (int**)realloc(resultado, capacidade * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacidade * sizeof(int));
                }

                resultado[*returnSize] = (int*)malloc(3 * sizeof(int));
                resultado[*returnSize][0] = nums[i];
                resultado[*returnSize][1] = nums[esquerda];
                resultado[*returnSize][2] = nums[direita];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (esquerda < direita && nums[esquerda] == nums[esquerda + 1])
                    esquerda++;
                while (esquerda < direita && nums[direita] == nums[direita - 1])
                    direita--;

                esquerda++;
                direita--;
            } 
            else if (soma < 0) {
                esquerda++;
            } 
            else {
                direita--;
            }
        }
    }

    return resultado;
}
