bool isUnivalTree(struct TreeNode* root) {
    if (!root) return true;

    int valor = root->val;

    bool verifica(struct TreeNode* no) {
        if (!no) return true;
        if (no->val != valor) return false;
        return verifica(no->left) && verifica(no->right);
    }

    return verifica(root);
}
