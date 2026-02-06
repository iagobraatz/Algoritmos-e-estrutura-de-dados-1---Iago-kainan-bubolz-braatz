/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int comparar(const void* a, const void* b) {
    long x = *(const int*)a;
    long y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) return NULL;
    
    qsort(nums, numsSize, sizeof(int), comparar);
    
    int capacidade = 1000;
    int** resultado = (int**)malloc(capacidade * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacidade * sizeof(int));
    
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int esquerda = j + 1;
            int direita = numsSize - 1;
            
            while (esquerda < direita) {
                long soma = (long)nums[i] + nums[j] + nums[esquerda] + nums[direita];
                
                if (soma == target) {
                    if (*returnSize == capacidade) {
                        capacidade *= 2;
                        resultado = (int**)realloc(resultado, capacidade * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacidade * sizeof(int));
                    }
                    
                    resultado[*returnSize] = (int*)malloc(4 * sizeof(int));
                    resultado[*returnSize][0] = nums[i];
                    resultado[*returnSize][1] = nums[j];
                    resultado[*returnSize][2] = nums[esquerda];
                    resultado[*returnSize][3] = nums[direita];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    
                    while (esquerda < direita && nums[esquerda] == nums[esquerda + 1]) esquerda++;
                    while (esquerda < direita && nums[direita] == nums[direita - 1]) direita--;
                    
                    esquerda++;
                    direita--;
                } else if (soma < target) {
                    esquerda++;
                } else {
                    direita--;
                }
            }
        }
    }
    
    return resultado;
}
