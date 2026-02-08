//Iago Kainan Bubolz Braatz - Trabalho prático 3 - AeD1 - M2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* construir(struct ListNode* inicio, struct ListNode* fim) {
    if (inicio == fim)
        return NULL;

    struct ListNode* p1 = inicio;
    struct ListNode* p2 = inicio; 

    while (p2 != fim && p2->next != fim) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    struct TreeNode* raiz = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    raiz->val = p1->val;
    raiz->left = construir(inicio, p1);
    raiz->right = construir(p1->next, fim);

    return raiz;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return construir(head, NULL);
}

void liberarArvore(struct TreeNode* raiz) {
    if (raiz == NULL)
        return;

    liberarArvore(raiz->left);
    liberarArvore(raiz->right);
    free(raiz);
}

void liberarLista(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void imprimir(struct TreeNode* raiz) {
    if (raiz == NULL) {
        printf("[]\n");
        return;
    }

    struct TreeNode* fila[20000]; 
    int frente = 0, tras = 0;

    fila[tras++] = raiz;

    printf("[");
    while (frente < tras) {
        struct TreeNode* atual = fila[frente++];

        if (atual != NULL) {
            printf("%d", atual->val);
            fila[tras++] = atual->left;
            fila[tras++] = atual->right;
        } else {
            printf("null");
        }

        if (frente < tras) printf(",");
    }
    printf("]\n");
}


int main() {
    int n, valor;
    struct ListNode *head = NULL, *ultimo = NULL;

    printf("Digite a quantidade de numeros: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("[]\n");
        return 0;
    }

    printf("Digite os %d numeros em ordem crescente: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);

        struct ListNode* novo = (struct ListNode*)malloc(sizeof(struct ListNode));
        novo->val = valor;
        novo->next = NULL;
        
        if (head == NULL) {
            head = novo;
            ultimo = head;
        } else {
            ultimo->next = novo;
            ultimo = novo;
        }
    }

    struct TreeNode* raiz = sortedListToBST(head);

    printf("\nSaida (Arvore Balanceada):\n");
    imprimir(raiz);

    liberarArvore(raiz);
    liberarLista(head);

    return 0;
}
