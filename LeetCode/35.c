int searchInsert(int* nums, int numsSize, int target) {
    int esquerda = 0;
    int direita = numsSize - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (nums[meio] == target)
            return meio;
        if (nums[meio] < target)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return esquerda;
}
