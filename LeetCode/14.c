#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* vazio = malloc(1);
        vazio[0] = '\0';
        return vazio;
    }

    int pos = 0;

    while (1) {
        char c = strs[0][pos];
        if (c == '\0') break;

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][pos] != c) {
                char* resultado = malloc(pos + 1);
                memcpy(resultado, strs[0], pos);
                resultado[pos] = '\0';
                return resultado;
            }
        }
        pos++;
    }

    char* resultado = malloc(pos + 1);
    memcpy(resultado, strs[0], pos);
    resultado[pos] = '\0';
    return resultado;
}
