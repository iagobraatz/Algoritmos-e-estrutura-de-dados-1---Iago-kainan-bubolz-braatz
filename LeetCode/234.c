/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdbool.h>

struct ListNode* inverter(struct ListNode* cabeca) {
    struct ListNode* anterior = NULL;
    struct ListNode* atual = cabeca;
    struct ListNode* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode* lento = head;
    struct ListNode* rapido = head;

    while (rapido->next != NULL && rapido->next->next != NULL) {
        lento = lento->next;
        rapido = rapido->next->next;
    }

    struct ListNode* segunda_metade = inverter(lento->next);
    struct ListNode* p1 = head;
    struct ListNode* p2 = segunda_metade;

    while (p2 != NULL) {
        if (p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}
