/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int comparar(const void* a, const void* b) {
    int* intervaloA = *(int**)a;
    int* intervaloB = *(int**)b;
    return intervaloA[0] - intervaloB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), comparar);

    int** resultado = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int indiceResultado = 0;

    resultado[0] = (int*)malloc(2 * sizeof(int));
    resultado[0][0] = intervals[0][0];
    resultado[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= resultado[indiceResultado][1]) {
            if (intervals[i][1] > resultado[indiceResultado][1])
                resultado[indiceResultado][1] = intervals[i][1];
        } else {
            indiceResultado++;
            resultado[indiceResultado] = (int*)malloc(2 * sizeof(int));
            resultado[indiceResultado][0] = intervals[i][0];
            resultado[indiceResultado][1] = intervals[i][1];
            (*returnColumnSizes)[indiceResultado] = 2;
        }
    }

    *returnSize = indiceResultado + 1;
    return resultado;
}
