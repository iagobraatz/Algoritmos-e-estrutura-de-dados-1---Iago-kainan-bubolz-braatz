#include <stdlib.h>
#include <string.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** resposta = malloc(sizeof(char*) * (2 * n));
    int indiceResposta = 0;
    int proximoEsperadoIndex = 0;

    for (int numero = 1; numero <= n; numero++) {
        resposta[indiceResposta] = malloc(5);
        strcpy(resposta[indiceResposta], "Push");
        indiceResposta++;

        if (numero == target[proximoEsperadoIndex]) {
            proximoEsperadoIndex++;
            if (proximoEsperadoIndex == targetSize) break;
        } else {
            resposta[indiceResposta] = malloc(4);
            strcpy(resposta[indiceResposta], "Pop");
            indiceResposta++;
        }
    }

    *returnSize = indiceResposta;
    return resposta;
}
