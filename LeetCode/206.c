/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* anterior = NULL;
    struct ListNode* atual = head;
    
    while (atual != NULL) {
        struct ListNode* proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    
    return anterior;
}
