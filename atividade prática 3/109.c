//Iago Kainan Bubolz Braatz - Trabalho prático 3 - AeD1 - M2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode* construir(struct ListNode* inicio, struct ListNode* fim) {
    if (inicio == fim)
        return NULL;

    struct ListNode* p1 = inicio;
    struct ListNode* p2 = inicio; 

    while (p2 != fim && p2->next != fim) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    struct TreeNode* raiz = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    raiz->val = p1->val;
    raiz->left = construir(inicio, p1);
    raiz->right = construir(p1->next, fim);

    return raiz;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return construir(head, NULL);
}

void liberarArvore(struct TreeNode* raiz) {
    if (raiz == NULL)
        return;

    liberarArvore(raiz->left);
    liberarArvore(raiz->right);
    free(raiz);
}
