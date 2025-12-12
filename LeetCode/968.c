#include <stdio.h>

#define NOT_COVERED 0
#define HAS_CAMERA 1
#define COVERED 2

int cameras = 0;

int dfs(struct TreeNode* root) {
    if (!root) return COVERED;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == NOT_COVERED || right == NOT_COVERED) {
        cameras++;
        return HAS_CAMERA;
    }

    if (left == HAS_CAMERA || right == HAS_CAMERA) {
        return COVERED;
    }

    return NOT_COVERED;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == NOT_COVERED) {
        cameras++; 
    }
    return cameras;
}
