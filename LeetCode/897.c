/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newRoot = NULL;
struct TreeNode* curr = NULL;

void inorder(struct TreeNode* node) {
    if (node == NULL) return;
    
    inorder(node->left);
    
    if (newRoot == NULL) {
        newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newRoot->val = node->val;
        newRoot->left = NULL;
        newRoot->right = NULL;
        curr = newRoot;
    } else {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = node->val;
        newNode->left = NULL;
        newNode->right = NULL;
        curr->right = newNode;
        curr = newNode;
    }
    
    inorder(node->right);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    newRoot = NULL;
    curr = NULL;
    inorder(root);
    return newRoot;
}
