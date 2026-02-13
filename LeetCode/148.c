/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mesclar(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* inicio = NULL;
    struct ListNode* fim = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct ListNode* menor;

        if (l1->val < l2->val) {
            menor = l1;
            l1 = l1->next;
        } else {
            menor = l2;
            l2 = l2->next;
        }

        if (inicio == NULL) {
            inicio = menor;
            fim = menor;
        } else {
            fim->next = menor;
            fim = menor;
        }
    }

    if (l1 != NULL) {
        if (inicio == NULL)
            inicio = l1;
        else
            fim->next = l1;
    }

    if (l2 != NULL) {
        if (inicio == NULL)
            inicio = l2;
        else
            fim->next = l2;
    }

    return inicio;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;

    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    struct ListNode* meio = p1->next;
    p1->next = NULL;

    struct ListNode* esquerda = sortList(head);
    struct ListNode* direita = sortList(meio);

    return mesclar(esquerda, direita);
}
