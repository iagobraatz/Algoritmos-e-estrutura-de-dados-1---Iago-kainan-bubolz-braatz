int alturaEsquerda(struct TreeNode* no) {
    int h = 0;
    while (no != NULL) {
        h++;
        no = no->left;
    }
    return h;
}

int alturaDireita(struct TreeNode* no) {
    int h = 0;
    while (no != NULL) {
        h++;
        no = no->right;
    }
    return h;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int he = alturaEsquerda(root);
    int hd = alturaDireita(root);

    if (he == hd)
        return (1 << he) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
