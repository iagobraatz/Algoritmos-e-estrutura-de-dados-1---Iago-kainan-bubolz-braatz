/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

struct TreeNode* construir(int* nums, int inicio, int fim) {
    if (inicio > fim)
        return NULL;
    
    int meio = inicio + (fim - inicio) / 2;
    
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = nums[meio];
    no->left = construir(nums, inicio, meio - 1);
    no->right = construir(nums, meio + 1, fim);
    
    return no;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return construir(nums, 0, numsSize - 1);
}
