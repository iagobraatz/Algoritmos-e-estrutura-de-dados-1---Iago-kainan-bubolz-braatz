//Iago Kainan Bubolz Braatz - Trabalho prático 2 - AED1 - M2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    struct ListNode* p_1 = head;
    struct ListNode* p_2 = head;

    while (p_2->next && p_2->next->next) {
        p_1 = p_1->next;
        p_2 = p_2->next->next;
    }

    struct ListNode* antes = NULL;
    struct ListNode* atual = p_1->next;
    struct ListNode* prox;

    while (atual!=NULL) {
        prox = atual->next;
        atual->next = antes;
        antes = atual;
        atual = prox;
    }

    p_1->next = NULL;

    struct ListNode* h1 = head;
    struct ListNode* h2 = antes;
    struct ListNode* t1;
    struct ListNode* t2;

    while (h2 != NULL) {
        t1 = h1->next;
        t2 = h2->next;
        h1->next = h2;
        h2->next = t1;
        h1 = t1;
        h2 = t2;
    }
}

struct ListNode* criarLista(int n) {
    if (n <= 0) return NULL;

    int valor;
    scanf("%d", &valor);

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = valor;
    head->next = NULL;

    struct ListNode* atual = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &valor);
        struct ListNode* novo = malloc(sizeof(struct ListNode));
        novo->val = valor;
        novo->next = NULL;
        atual->next = novo;
        atual = novo;
    }
    return head;
}

void imprimirLista(struct ListNode* head) {
    while (head!=NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    printf("Digite os %d valores da lista:\n", n);
    struct ListNode* head = criarLista(n);

    reorderList(head);

    printf("Lista reordenada:\n");
    imprimirLista(head);

    return 0;
}
