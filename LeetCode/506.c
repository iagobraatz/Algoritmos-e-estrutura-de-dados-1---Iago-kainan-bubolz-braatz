/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int comparar(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (y > x)
        return 1;
    else if (y < x)
        return -1;
    else
        return 0;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {

    int* copia = (int*) malloc(scoreSize * sizeof(int));
    int i;

    for (i = 0; i < scoreSize; i++) {
        copia[i] = score[i];
    }

    qsort(copia, scoreSize, sizeof(int), comparar);

    char** resposta = (char**) malloc(scoreSize * sizeof(char*));

    for (i = 0; i < scoreSize; i++) {

        int posicao = 0;
        int j;

        for (j = 0; j < scoreSize; j++) {
            if (score[i] == copia[j]) {
                posicao = j + 1;
                break;
            }
        }

        resposta[i] = (char*) malloc(20 * sizeof(char));

        if (posicao == 1) {
            strcpy(resposta[i], "Gold Medal");
        }
        else if (posicao == 2) {
            strcpy(resposta[i], "Silver Medal");
        }
        else if (posicao == 3) {
            strcpy(resposta[i], "Bronze Medal");
        }
        else {
            sprintf(resposta[i], "%d", posicao);
        }
    }

    *returnSize = scoreSize;
    return resposta;
}
