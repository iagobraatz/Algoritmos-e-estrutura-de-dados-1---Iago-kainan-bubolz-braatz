struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* cauda = &dummy;
    dummy.next = NULL;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            cauda->next = list1;
            list1 = list1->next;
        } else {
            cauda->next = list2;
            list2 = list2->next;
        }
        cauda = cauda->next;
    }
    
    if (list1 != NULL) {
        cauda->next = list1;
    } else {
        cauda->next = list2;
    }
    
    return dummy.next;
}
