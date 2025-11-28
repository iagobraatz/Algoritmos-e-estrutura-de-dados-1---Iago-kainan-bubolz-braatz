struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    struct ListNode* atual = head;
    int tamanho = 1;
    while (atual->next) {
        atual = atual->next;
        tamanho++;
    }

    atual->next = head;

    k = k % tamanho;
    int passos = tamanho - k;

    struct ListNode* novoFim = head;
    for (int i = 1; i < passos; i++) {
        novoFim = novoFim->next;
    }

    struct ListNode* novoInicio = novoFim->next;
    novoFim->next = NULL;

    return novoInicio;
}
