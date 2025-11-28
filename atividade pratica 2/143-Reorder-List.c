//Iago Kainan Bubolz Braatz - Trabalho prático 2 - AED1 - M2 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

    while (h2!=NULL) {
        t1 = h1->next;
        t2 = h2->next;
        h1->next = h2;
        h2->next = t1;
        h1 = t1;
        h2 = t2;
    }
}
