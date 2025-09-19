// AED1 - Aula 1
// Iago Kainan Bubolz Braatz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionar(char*** nomes, int* qtd, const char* nome);
void remover(char*** nomes, int* qtd, const char* nome);
void listar(char** nomes, int qtd);

int main() {
    char** nomes = NULL;  
    int qtd = 0;          
    int opcao;
    char nome[100];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar nome\n");
        printf("2. Remover nome\n");
        printf("3. Listar nomes\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                adicionar(&nomes, &qtd, nome);
                break;

            case 2:
                printf("Nome para remover: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remover(&nomes, &qtd, nome);
                break;

            case 3:
                listar(nomes, qtd);
                break;

            case 4:
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    
    for (int i = 0; i < qtd; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

void adicionar(char*** nomes, int* qtd, const char* nome) {
    *nomes = realloc(*nomes, (*qtd + 1) * sizeof(char*));
    (*nomes)[*qtd] = malloc(strlen(nome) + 1);
    strcpy((*nomes)[*qtd], nome);
    (*qtd)++;
}

void remover(char*** nomes, int* qtd, const char* nome) {
    for (int i = 0; i < *qtd; i++) {
        if (strcmp((*nomes)[i], nome) == 0) {
            free((*nomes)[i]);
            for (int j = i; j < *qtd - 1; j++) {
                (*nomes)[j] = (*nomes)[j + 1];
            }
            (*qtd)--;
            *nomes = realloc(*nomes, (*qtd) * sizeof(char*));
            printf("Nome removido.\n");
            return;
        }
    }
    printf("Nome não encontrado.\n");
}

void listar(char** nomes, int qtd) {
    if (qtd == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\n--- Lista de nomes ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s\n", i + 1, nomes[i]);
    }
}
