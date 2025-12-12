#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* inicio = NULL;
    struct ListNode* atual = NULL;

    int vaiUm = 0;

    while (l1 || l2 || vaiUm) {
        int soma = vaiUm;
        if (l1) {
            soma += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            soma += l2->val;
            l2 = l2->next;
        }

        struct ListNode* novo = malloc(sizeof(struct ListNode));
        novo->val = soma % 10;
        novo->next = NULL;

        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->next = novo;
            atual = novo;
        }

        vaiUm = soma / 10;
    }

    return inicio;
}
