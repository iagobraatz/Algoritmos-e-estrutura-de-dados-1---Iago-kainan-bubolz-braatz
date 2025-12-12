int altura(struct TreeNode* no) {
    if (!no) return 0;

    int esq = altura(no->left);
    if (esq == -1) return -1;

    int dir = altura(no->right);
    if (dir == -1) return -1;

    if (esq - dir > 1 || dir - esq > 1) return -1;

    return (esq > dir ? esq : dir) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return altura(root) != -1;
}
