/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* resultado = (int*)malloc((n + 1) * sizeof(int));
    
    resultado[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        resultado[i] = resultado[i >> 1] + (i & 1);
    }
    
    return resultado;
}
