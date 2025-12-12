bool simetricos(struct TreeNode* a, struct TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val &&
           simetricos(a->left, b->right) &&
           simetricos(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return simetricos(root->left, root->right);
}
