#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dfs(struct TreeNode* no, char** lista, int* tam, char* caminho, int len) {
    int n = sprintf(caminho + len, "%d", no->val);
    len += n;

    if (!no->left && !no->right) {
        lista[*tam] = malloc(len + 1);
        memcpy(lista[*tam], caminho, len);
        lista[*tam][len] = '\0';
        (*tam)++;
        return;
    }

    caminho[len++] = '-';
    caminho[len++] = '>';

    if (no->left) dfs(no->left, lista, tam, caminho, len);
    if (no->right) dfs(no->right, lista, tam, caminho, len);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    char** lista = malloc(200 * sizeof(char*));
    char caminho[200];
    dfs(root, lista, returnSize, caminho, 0);
    return lista;
}
