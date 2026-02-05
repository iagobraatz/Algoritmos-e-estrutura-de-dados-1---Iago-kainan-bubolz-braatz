/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* atual = &dummy;

    while (atual->next != NULL) {
        if (atual->next->val == val) {
            struct ListNode* temp = atual->next;
            atual->next = temp->next;
            free(temp);
        } else {
            atual = atual->next;
        }
    }

    return dummy.next;
}
