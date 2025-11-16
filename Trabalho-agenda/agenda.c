#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_NOME (100 * sizeof(char))
#define TAM_EMAIL (100 * sizeof(char))
#define TAM_IDADE (sizeof(int))
#define PESSOA (TAM_NOME + TAM_EMAIL + TAM_IDADE)

int main() {
    void *pBuffer = malloc(sizeof(int) * 3); 
    void *menu = pBuffer;
    void *qtde = (char *)pBuffer + sizeof(int);
    void *i = (char *)pBuffer + sizeof(int) * 2;

    void *aux = NULL;
    void *comecoPessoa = NULL;
    void *incrementador = NULL;
    void *final = NULL;
    void *atual = NULL;
    void *temp = NULL;

    *(int *)menu = 0;
    *(int *)qtde = 0;
    *(int *)i = 0;

    while (1) {
        printf("\n- - - - M E N U - - - -");
        printf("\n1. ADICIONAR PESSOA");
        printf("\n2.REMOVER PESSOA");
        printf("\n3.BUSCAR PESSOA");
        printf("\n4.LISTAR TUDO");
        printf("\n5.SAIR");
        printf("\n- - - - - - - - - - - -\n");

        printf("\nDigite o numero da opcao desejada : ");
        scanf("%d", (int *)menu);
        getchar();

        switch (*(int *)menu) {
            
            case 1:
    pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde) + TAM_NOME);
    menu = pBuffer;
    qtde = (char *)pBuffer + sizeof(int);
    i = (char *)pBuffer + sizeof(int) * 2;

    incrementador = (char *)pBuffer + sizeof(int) * 3 + (PESSOA * (*(int *)qtde));

    printf("NOME: ");
    fgets((char *)incrementador, TAM_NOME, stdin);
    ((char *)incrementador)[strcspn((char *)incrementador, "\n")] = 0;

    if (*(int *)qtde > 0) {
        comecoPessoa = (char *)pBuffer + sizeof(int) * 3;
        atual = comecoPessoa;

        for (*(int *)i = 0; *(int *)i < *(int *)qtde; (*(int *)i)++) {
            if (strcmp((char *)atual, (char *)incrementador) == 0) {
                printf("Erro: ja existe uma pessoa com esse nome!\n");
                pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde));
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;
                break;
            }
            atual = (char *)atual + PESSOA;
        }

        if (*(int *)i != *(int *)qtde) break;
    }

    (*(int *)qtde)++;

    pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde));
    menu = pBuffer;
    qtde = (char *)pBuffer + sizeof(int);
    i = (char *)pBuffer + sizeof(int) * 2;

    temp = (char *)pBuffer + sizeof(int) * 3 + PESSOA * (*(int *)qtde - 1);

    strcpy((char *)temp, (char *)incrementador);

    printf("IDADE: ");
    scanf("%d", (int *)(temp + TAM_NOME));
    getchar();

    printf("EMAIL: ");
    fgets((char *)(temp + TAM_NOME + TAM_IDADE), TAM_EMAIL, stdin);
    ((char *)(temp + TAM_NOME + TAM_IDADE))[strcspn((char *)(temp + TAM_NOME + TAM_IDADE), "\n")] = 0;

    printf("Pessoa adicionada com sucesso!\n");
    break;


            case 2:
                if (*(int *)qtde == 0) {
                    printf("Agenda vazia!\n");
                    break;
                }

                printf("REMOVER NOME: ");
                pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde) + TAM_NOME);
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;

                comecoPessoa = (char *)pBuffer + sizeof(int) * 3;
                atual = comecoPessoa;
                incrementador = (char *)pBuffer + sizeof(int) * 3 + (PESSOA * (*(int *)qtde));

                fgets((char *)incrementador, TAM_NOME, stdin);
                ((char *)incrementador)[strcspn((char *)incrementador, "\n")] = 0;

                temp = NULL;
                for (*(int *)i = 0; *(int *)i < *(int *)qtde; (*(int *)i)++) {
                    if (strcmp((char *)incrementador, (char *)atual) == 0) {
                        temp = atual;
                        break;
                    }
                    atual = (char *)atual + PESSOA;
                }

                if (temp == NULL) {
                    printf("Pessoa nao encontrada!\n");
                } else {
                    if (*(int *)qtde > 1) {
                        aux = malloc(PESSOA);
                        incrementador = (char *)pBuffer + sizeof(int) * 3 + PESSOA * (*(int *)qtde - 1);
                        memcpy(aux, incrementador, PESSOA);
                        memcpy(temp, aux, PESSOA);
                        free(aux);
                    }

                    (*(int *)qtde)--;
                    pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde));
                    menu = pBuffer;
                    qtde = (char *)pBuffer + sizeof(int);
                    i = (char *)pBuffer + sizeof(int) * 2;
                    printf("Pessoa removida com sucesso!\n");
                }
                break;

            case 3:
                if (*(int *)qtde == 0) {
                    printf("Agenda vazia!\n");
                    break;
                }

                printf("BUSCAR NOME: ");
                pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde) + TAM_NOME);
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;

                comecoPessoa = (char *)pBuffer + sizeof(int) * 3;
                atual = comecoPessoa;
                incrementador = (char *)pBuffer + sizeof(int) * 3 + (PESSOA * (*(int *)qtde));

                fgets((char *)incrementador, TAM_NOME, stdin);
                ((char *)incrementador)[strcspn((char *)incrementador, "\n")] = 0;

                temp = NULL;
                for (*(int *)i = 0; *(int *)i < *(int *)qtde; (*(int *)i)++) {
                    if (strcmp((char *)incrementador, (char *)atual) == 0) {
                        temp = atual;
                        break;
                    }
                    atual = (char *)atual + PESSOA;
                }

                if (temp == NULL) {
                    printf("Pessoa nao encontrada!\n");
                } else {
                    printf("\n- - - - I N F O - - - -\n");
                    printf("NOME:\t%s\n", (char *)temp);
                    printf("IDADE:\t%d\n", *(int *)((char *)temp + TAM_NOME));
                    printf("EMAIL:\t%s\n", (char *)((char *)temp + TAM_NOME + TAM_IDADE));
                    printf("- - - - - - - - - - - -\n");
                }

                pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde));
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;
                break;

            case 4:
                if (*(int *)qtde == 0) {
                    printf("- - - - - - - - - - - -\n");
                    printf("Agenda Vazia!!!");
                    printf("\n- - - - - - - - - - - -\n");
                    break;
                }

                pBuffer = realloc(pBuffer, (sizeof(int) * 4) + PESSOA * (*(int *)qtde));
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;
                final = (char *)pBuffer + sizeof(int) * 3 + PESSOA * (*(int *)qtde);

                *(int *)final = *(int *)qtde;

                comecoPessoa = (char *)pBuffer + sizeof(int) * 3;
                incrementador = comecoPessoa;

                while ((*(int *)final) > 0) {
                    printf("- - - - - - - - - - - -\n");
                    printf("NOME:\t%s\n", (char *)incrementador);
                    printf("IDADE:\t%d\n", *(int *)((char *)incrementador + TAM_NOME));
                    printf("EMAIL:\t%s\n", (char *)((char *)incrementador + TAM_NOME + TAM_IDADE));
                    printf("- - - - - - - - - - - -\n");
                    incrementador = (char *)incrementador + PESSOA;
                    (*(int *)final)--;
                }

                pBuffer = realloc(pBuffer, (sizeof(int) * 3) + PESSOA * (*(int *)qtde));
                menu = pBuffer;
                qtde = (char *)pBuffer + sizeof(int);
                i = (char *)pBuffer + sizeof(int) * 2;
                break;

            case 5:
                free(pBuffer);
                exit(0);
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
//iago kainan bubolz braatz
