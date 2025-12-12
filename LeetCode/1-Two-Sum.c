#include <stdlib.h>

typedef struct {
    int chave;
    int indice;
    int usado;
} ItemHash;

int hash(int chave, int tamanho) {
    long long k = chave;
    if (k < 0) k = -k;
    return k % tamanho;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* resposta = malloc(2 * sizeof(int));

    int tamanhoTabela = numsSize * 2 + 1;
    ItemHash* tabela = calloc(tamanhoTabela, sizeof(ItemHash));

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        int pos = hash(complemento, tamanhoTabela);

        while (tabela[pos].usado) {
            if (tabela[pos].chave == complemento) {
                resposta[0] = tabela[pos].indice;
                resposta[1] = i;
                free(tabela);
                return resposta;
            }
            pos = (pos + 1) % tamanhoTabela;
        }

        int pos2 = hash(nums[i], tamanhoTabela);
        while (tabela[pos2].usado)
            pos2 = (pos2 + 1) % tamanhoTabela;

        tabela[pos2].usado = 1;
        tabela[pos2].chave = nums[i];
        tabela[pos2].indice = i;
    }

    free(tabela);
    return NULL;
}
