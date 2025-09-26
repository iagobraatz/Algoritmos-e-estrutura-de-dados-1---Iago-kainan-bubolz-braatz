#include <stdio.h>
#include <stdlib.h>

char* alocarstring(int tamanho) {
    char *str = (char*)malloc((tamanho + 1) * sizeof(char));
    if(str == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return str;
}

int ehvogal(char c) {
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
       c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
       c == 'u' || c == 'U') {
        return 1;
    }
    return 0;
}

int main() {
    int tamanho, i, j = 0;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    char *str = alocarstring(tamanho);

    printf("Digite o conteúdo da string: ");
    scanf(" %[^\n]", str);

    char *semvogais = (char*)malloc((tamanho + 1) * sizeof(char));
    if(semvogais == NULL) {
        printf("Erro de alocação!\n");
        free(str);
        exit(1);
    }

    for(i = 0; str[i] != '\0'; i++) {
        if(!ehvogal(str[i])) {
            semvogais[j++] = str[i];
        }
    }
    semvogais[j] = '\0';

    printf("String sem vogais: %s\n", semvogais);

    free(str);
    free(semvogais);

    return 0;
}
