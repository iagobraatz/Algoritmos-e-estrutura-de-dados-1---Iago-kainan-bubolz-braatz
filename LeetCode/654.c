int buscarMax(int* nums, int inicio, int fim) {
    int idx = inicio;
    for (int i = inicio + 1; i <= fim; i++)
        if (nums[i] > nums[idx])
            idx = i;
    return idx;
}

struct TreeNode* construir(int* nums, int inicio, int fim) {
    if (inicio > fim) return NULL;

    int idx = buscarMax(nums, inicio, fim);

    struct TreeNode* no = malloc(sizeof(struct TreeNode));
    no->val = nums[idx];
    no->left = construir(nums, inicio, idx - 1);
    no->right = construir(nums, idx + 1, fim);

    return no;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return construir(nums, 0, numsSize - 1);
}
