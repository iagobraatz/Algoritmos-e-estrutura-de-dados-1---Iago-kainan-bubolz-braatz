/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int buscarPrimeira(int* nums, int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1;
    int resultado = -1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (nums[meio] == alvo) {
            resultado = meio;
            direita = meio - 1;
        } else if (nums[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return resultado;
}

int buscarUltima(int* nums, int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1;
    int resultado = -1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (nums[meio] == alvo) {
            resultado = meio;
            esquerda = meio + 1;
        } else if (nums[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return resultado;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* resultado = (int*)malloc(2 * sizeof(int));
    
    resultado[0] = buscarPrimeira(nums, numsSize, target);
    resultado[1] = buscarUltima(nums, numsSize, target);
    
    return resultado;
}
