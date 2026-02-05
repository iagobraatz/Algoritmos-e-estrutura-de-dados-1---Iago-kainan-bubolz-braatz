/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* atual = head;

    while (atual != NULL && atual->next != NULL) {
        if (atual->val == atual->next->val) {
            struct ListNode* temp = atual->next;
            atual->next = atual->next->next;
            free(temp);
        } else {
            atual = atual->next;
        }
    }

    return head;
}
