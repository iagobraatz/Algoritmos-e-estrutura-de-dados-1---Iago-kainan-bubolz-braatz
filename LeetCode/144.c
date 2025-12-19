int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    void preorder(struct TreeNode* node) {
        if (node == NULL) return;

        result[(*returnSize)++] = node->val; 
        preorder(node->left);               
        preorder(node->right);              
    }

    preorder(root);
    return result;
}
