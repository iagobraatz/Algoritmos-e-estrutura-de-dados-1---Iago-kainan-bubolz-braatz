struct TreeNode* invertTree(struct TreeNode* raiz) {
    if (!raiz) return raiz;

    struct TreeNode* temp = raiz->left;
    raiz->left = raiz->right;
    raiz->right = temp;

    invertTree(raiz->left);
    invertTree(raiz->right);

    return raiz;
}
