/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode** array;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->array = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(Queue* q, struct TreeNode* node) {
    if (q->rear < q->size) {
        q->array[q->rear++] = node;
    }
}

struct TreeNode* dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->array[q->front++];
    }
    return NULL;
}

int isEmpty(Queue* q) {
    return q->front >= q->rear;
}

void freeQueue(Queue* q) {
    free(q->array);
    free(q);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    Queue* q = createQueue(10000);
    enqueue(q, root);
    
    double* result = (double*)malloc(sizeof(double) * 10000);
    *returnSize = 0;
    
    while (!isEmpty(q)) {
        int levelSize = q->rear - q->front;
        long long sum = 0;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            sum += node->val;
            
            if (node->left != NULL) {
                enqueue(q, node->left);
            }
            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }
        
        result[*returnSize] = (double)sum / levelSize;
        (*returnSize)++;
    }
    
    freeQueue(q);
    return result;
}
