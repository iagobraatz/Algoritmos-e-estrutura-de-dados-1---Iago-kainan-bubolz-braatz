#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int altura(struct TreeNode* no) {
    if (!no) return -1;
    int e = altura(no->left);
    int d = altura(no->right);
    return (e > d ? e : d) + 1;
}

void preencher(struct TreeNode* no, char*** res, int linha, int col, int h) {
    if (!no) return;

    char buf[12];
    sprintf(buf, "%d", no->val);
    res[linha][col] = malloc(strlen(buf) + 1);
    strcpy(res[linha][col], buf);

    if (no->left)
        preencher(no->left, res, linha + 1, col - (1 << (h - linha - 1)), h);
    if (no->right)
        preencher(no->right, res, linha + 1, col + (1 << (h - linha - 1)), h);
}

char*** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int h = altura(root);
    int linhas = h + 1;
    int colunas = (1 << (h + 1)) - 1;

    char*** res = malloc(linhas * sizeof(char**));
    *returnColumnSizes = malloc(linhas * sizeof(int));
    *returnSize = linhas;

    for (int i = 0; i < linhas; i++) {
        (*returnColumnSizes)[i] = colunas;
        res[i] = malloc(colunas * sizeof(char*));
        for (int j = 0; j < colunas; j++) {
            res[i][j] = malloc(1);
            res[i][j][0] = '\0';
        }
    }

    preencher(root, res, 0, (colunas - 1) / 2, h);
    return res;
}
