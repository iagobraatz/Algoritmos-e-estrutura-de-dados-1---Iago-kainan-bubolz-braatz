#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int tamanho = strlen(s);
    if (numRows == 1 || numRows >= tamanho)
        return strdup(s);
    
    char* resultado = (char*)malloc((tamanho + 1) * sizeof(char));
    int indice = 0;
    int ciclo = 2 * numRows - 2;
    
    for (int linha = 0; linha < numRows; linha++) {
        for (int i = linha; i < tamanho; i += ciclo) {
            resultado[indice++] = s[i];
            
            int diagonal = i + ciclo - 2 * linha;
            if (linha != 0 && linha != numRows - 1 && diagonal < tamanho)
                resultado[indice++] = s[diagonal];
        }
    }
    
    resultado[indice] = '\0';
    return resultado;
}
