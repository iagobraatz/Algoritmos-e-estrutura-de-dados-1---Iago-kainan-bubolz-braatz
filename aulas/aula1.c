// AED1 - Aula 1
// Iago Kainan Bubolz Braatz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nomes = NULL;
int tamanho = 0;

void AdicionarNome() {
    char buffer[100];
    int i, j;

    printf("Digite o nome para adicionar: ");
    scanf(" %[^\n]", buffer);

    int cont = 0;
    while(buffer[cont] != '\0') cont++;

    nomes = realloc(nomes, tamanho + cont + 2);

    if(tamanho == 0) {
        for(i = 0; i < cont; i++) nomes[i] = buffer[i];
        nomes[cont] = '\0';
        tamanho = cont;
    } else {
        nomes[tamanho] = ' ';
        for(i = 0; i < cont; i++) nomes[tamanho + 1 + i] = buffer[i];
        nomes[tamanho + 1 + cont] = '\0';
        tamanho += cont + 1;
    }
}

void RemoverNome() {
    if(tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    char buffer[100];
    int i, j, k;

    printf("Digite o nome para remover: ");
    scanf(" %[^\n]", buffer);

    int cont = 0;
    while(buffer[cont] != '\0') cont++;

    for(i = 0; i <= tamanho - cont; i++) {
        int igual = 1;
        for(j = 0; j < cont; j++) {
            if(nomes[i+j] != buffer[j]) {
                igual = 0;
                break;
            }
        }
        if(igual) {
            for(k = i; k < tamanho - cont; k++) nomes[k] = nomes[k + cont + 1];
            tamanho -= cont + 1;
            nomes = realloc(nomes, tamanho + 1);
            nomes[tamanho] = '\0';
            printf("Nome removido.\n");
            return;
        }
    }

    printf("Nome não encontrado.\n");
}

void ListarNomes() {
    if(tamanho == 0) {
        printf("Lista vazia.\n");
    } else {
        for(int i = 0; i < tamanho; i++) printf("%c", nomes[i]);
        printf("\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n1) Adicionar nome\n2) Remover nome\n3) Listar\n4) Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: AdicionarNome(); break;
            case 2: RemoverNome(); break;
            case 3: ListarNomes(); break;
            case 4: break;
            default: printf("Opção inválida!\n"); break;
        }
    } while(opcao != 4);

    free(nomes);
    return 0;
}
