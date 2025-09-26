#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for(int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    int numsSize;
    printf("Digite o tamanho do array: ");
    scanf("%d", &numsSize);

    int* nums = (int*) malloc(numsSize * sizeof(int));
    if (nums == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for(int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = runningSum(nums, numsSize, &returnSize);

    printf("Running sum: ");
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(nums);
    return 0;
}
