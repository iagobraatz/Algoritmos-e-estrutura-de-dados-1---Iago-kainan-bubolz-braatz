#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_PESSOA (TAM_NOME + sizeof(int) + TAM_EMAIL)

int main() {
    void *pBuffer = malloc(sizeof(int)*4 + TAM_NOME);
    if (!pBuffer) return 1;

    // Inicialização
    // [0-3]: opção do menu
    // [4-7]: contador de pessoas  
    // [8-11]: índice para loops
    // [12-15]: flag de encontrou (0 = não, 1 = sim)
    *(int*)(pBuffer + 0) = 0;
    *(int*)(pBuffer + 4) = 0;
    *(int*)(pBuffer + 8) = 0;
    *(int*)(pBuffer + 12) = 0;

    while (1) {
        printf("------------------------\n");
        printf("MENU:\n");
        printf("1- Adicionar Pessoa\n");
        printf("2- Remover Pessoa\n");
        printf("3- Buscar Pessoa\n");
        printf("4- Listar Todos\n");
        printf("5- Sair\n");
        printf("Digite o numero da opcao: ");

        scanf("%d", (int*)(pBuffer + 0));
        getchar();

        switch (*(int*)(pBuffer + 0)) {

        case 1: {
            // Adicionar nova pessoa
            *(int*)(pBuffer + 4) += 1;
            pBuffer = realloc(pBuffer, sizeof(int)*4 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 4)));
            if (!pBuffer) return 1;

            // Calcula a posição direta para a nova pessoa
            char *novaPessoa = (char*)pBuffer + 16 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 4) - 1);
            
            // Ler dados diretamente na posição final
            printf("Nome: ");
            fgets(novaPessoa, TAM_NOME, stdin);
            novaPessoa[strcspn(novaPessoa, "\n")] = 0;

            printf("Idade: ");
            scanf("%d", (int*)(novaPessoa + TAM_NOME));
            getchar();

            printf("Email: ");
            fgets(novaPessoa + TAM_NOME + sizeof(int), TAM_EMAIL, stdin);
            (novaPessoa + TAM_NOME + sizeof(int))[strcspn(novaPessoa + TAM_NOME + sizeof(int), "\n")] = 0;
            
            printf("Pessoa adicionada com sucesso!\n");
            break;
        }

        case 2: {
            // Remover pessoa
            if (*(int*)(pBuffer + 4) == 0) {
                printf("Agenda vazia!\n");
                break;
            }

            printf("Nome para remover: ");
            fgets((char*)pBuffer + 16, TAM_NOME, stdin);
            ((char*)pBuffer + 16)[strcspn((char*)pBuffer + 16, "\n")] = 0;

            *(int*)(pBuffer + 8) = 0;
            *(int*)(pBuffer + 12) = 0; // flag encontrou = 0
            
            while (*(int*)(pBuffer + 8) < *(int*)(pBuffer + 4)) {
                char *pessoaAtual = (char*)pBuffer + 16 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 8));
                
                if (strcmp((char*)pBuffer + 16, pessoaAtual) == 0) {
                    // Encontrou a pessoa para remover
                    if (*(int*)(pBuffer + 4) > 1 && *(int*)(pBuffer + 8) != *(int*)(pBuffer + 4) - 1) {
                        // Substituir pela última pessoa (se não for a última)
                        char *ultimaPessoa = (char*)pBuffer + 16 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 4) - 1);
                        memcpy(pessoaAtual, ultimaPessoa, TAM_PESSOA);
                    }
                    
                    *(int*)(pBuffer + 4) -= 1;
                    pBuffer = realloc(pBuffer, sizeof(int)*4 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 4)));
                    printf("Pessoa removida!\n");
                    *(int*)(pBuffer + 12) = 1; // flag encontrou = 1
                    break;
                }
                *(int*)(pBuffer + 8) += 1;
            }

            if (*(int*)(pBuffer + 12) == 0)
                printf("Pessoa nao encontrada!\n");
            break;
        }

        case 3: {
            // Buscar pessoa
            if (*(int*)(pBuffer + 4) == 0) {
                printf("Agenda vazia!\n");
                break;
            }

            printf("Nome para buscar: ");
            fgets((char*)pBuffer + 16, TAM_NOME, stdin);
            ((char*)pBuffer + 16)[strcspn((char*)pBuffer + 16, "\n")] = 0;

            *(int*)(pBuffer + 8) = 0;
            *(int*)(pBuffer + 12) = 0; // flag encontrou = 0
            
            while (*(int*)(pBuffer + 8) < *(int*)(pBuffer + 4)) {
                char *pessoaAtual = (char*)pBuffer + 16 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 8));
                
                if (strcmp((char*)pBuffer + 16, pessoaAtual) == 0) {
                    printf("\n--- Pessoa Encontrada ---\n");
                    printf("Nome: %s\n", pessoaAtual);
                    printf("Idade: %d\n", *(int*)(pessoaAtual + TAM_NOME));
                    printf("Email: %s\n", pessoaAtual + TAM_NOME + sizeof(int));
                    printf("-----------------------\n");
                    *(int*)(pBuffer + 12) = 1; // flag encontrou = 1
                    break;
                }
                *(int*)(pBuffer + 8) += 1;
            }

            if (*(int*)(pBuffer + 12) == 0)
                printf("Pessoa nao encontrada!\n");
            break;
        }

        case 4: {
            // Listar todas as pessoas
            if (*(int*)(pBuffer + 4) == 0) {
                printf("Agenda vazia!\n");
                break;
            }

            printf("\n--- Lista de Pessoas ---\n");
            *(int*)(pBuffer + 8) = 0;
            
            while (*(int*)(pBuffer + 8) < *(int*)(pBuffer + 4)) {
                char *pessoaAtual = (char*)pBuffer + 16 + TAM_NOME + TAM_PESSOA * (*(int*)(pBuffer + 8));
                
                printf("Pessoa %d:\n", *(int*)(pBuffer + 8) + 1);
                printf("  Nome: %s\n", pessoaAtual);
                printf("  Idade: %d\n", *(int*)(pessoaAtual + TAM_NOME));
                printf("  Email: %s\n", pessoaAtual + TAM_NOME + sizeof(int));
                printf("\n");
                
                *(int*)(pBuffer + 8) += 1;
            }
            printf("-----------------------\n");
            break;
        }

        case 5:
            free(pBuffer);
            return 0;

        default:
            printf("Opcao invalida!\n");
        }
    }
}
