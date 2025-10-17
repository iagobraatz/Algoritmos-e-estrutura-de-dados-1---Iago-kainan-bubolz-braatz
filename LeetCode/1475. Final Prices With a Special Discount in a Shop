#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* result = (int*)malloc(pricesSize * sizeof(int));
    int* stack = (int*)malloc(pricesSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < pricesSize; i++) {
        result[i] = prices[i];
    }
    
    for (int i = 0; i < pricesSize; i++) {
        while (top != -1 && prices[i] <= prices[stack[top]]) {
            int idx = stack[top--];
            result[idx] = prices[idx] - prices[i];
        }
        stack[++top] = i;
    }
    
    free(stack);
    return result;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int prices1[] = {8, 4, 6, 2, 3};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    int returnSize1;
    
    printf("Input: ");
    printArray(prices1, size1);
    
    int* result1 = finalPrices(prices1, size1, &returnSize1);
    printf("Output: ");
    printArray(result1, returnSize1);
    printf("\n");
    
    free(result1);
    
    int prices2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    int returnSize2;
    
    printf("Input: ");
    printArray(prices2, size2);
    
    int* result2 = finalPrices(prices2, size2, &returnSize2);
    printf("Output: ");
    printArray(result2, returnSize2);
    printf("\n");
    
    free(result2);
    
    int prices3[] = {10, 1, 1, 6};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    int returnSize3;
    
    printf("Input: ");
    printArray(prices3, size3);
    
    int* result3 = finalPrices(prices3, size3, &returnSize3);
    printf("Output: ");
    printArray(result3, returnSize3);
    
    free(result3);
    
    return 0;
}

//Iago Kainan Bubolz Braatz
