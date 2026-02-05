int search(int* nums, int numsSize, int target) {
    int esquerda = 0;
    int direita = numsSize - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (nums[meio] == target)
            return meio;

        if (nums[esquerda] <= nums[meio]) {
            if (target >= nums[esquerda] && target < nums[meio])
                direita = meio - 1;
            else
                esquerda = meio + 1;
        } else {
            if (target > nums[meio] && target <= nums[direita])
                esquerda = meio + 1;
            else
                direita = meio - 1;
        }
    }

    return -1;
}
