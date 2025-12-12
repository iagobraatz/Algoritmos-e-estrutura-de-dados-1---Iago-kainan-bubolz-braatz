int somaTilt(struct TreeNode* no, int* total) {
    if (!no) return 0;

    int esq = somaTilt(no->left, total);
    int dir = somaTilt(no->right, total);

    int t = esq - dir;
    if (t < 0) t = -t;

    *total += t;

    return esq + dir + no->val;
}

int findTilt(struct TreeNode* root) {
    int total = 0;
    somaTilt(root, &total);
    return total;
}
