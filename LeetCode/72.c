#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minDistance(char* word1, char* word2) {
    int tamanho1 = strlen(word1);
    int tamanho2 = strlen(word2);

    int** dp = (int**)malloc((tamanho1 + 1) * sizeof(int*));
    for (int i = 0; i <= tamanho1; i++)
        dp[i] = (int*)malloc((tamanho2 + 1) * sizeof(int));

    for (int i = 0; i <= tamanho1; i++)
        dp[i][0] = i;

    for (int j = 0; j <= tamanho2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= tamanho1; i++) {
        for (int j = 1; j <= tamanho2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int inserir = dp[i][j - 1];
                int deletar = dp[i - 1][j];
                int substituir = dp[i - 1][j - 1];
                dp[i][j] = 1 + min(min(inserir, deletar), substituir);
            }
        }
    }

    int resultado = dp[tamanho1][tamanho2];

    for (int i = 0; i <= tamanho1; i++)
        free(dp[i]);
    free(dp);

    return resultado;
}
