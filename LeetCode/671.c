long buscar(struct TreeNode* root, int minimo) {
    if (!root)
        return -1;
    
    if (root->val > minimo)
        return root->val;
    
    long esquerda = buscar(root->left, minimo);
    long direita = buscar(root->right, minimo);
    
    if (esquerda == -1)
        return direita;
    if (direita == -1)
        return esquerda;
    
    return esquerda < direita ? esquerda : direita;
}

int findSecondMinimumValue(struct TreeNode* root) {
    if (!root)
        return -1;
    
    long resultado = buscar(root, root->val);
    return (int)resultado;
}
