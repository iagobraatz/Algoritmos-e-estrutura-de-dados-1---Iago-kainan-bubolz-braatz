void inverter(int* nums, int inicio, int fim) {
    while (inicio < fim) {
        int temp = nums[inicio];
        nums[inicio] = nums[fim];
        nums[fim] = temp;
        inicio++;
        fim--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) return;

    k = k % numsSize;

    inverter(nums, 0, numsSize - 1);
    inverter(nums, 0, k - 1);
    inverter(nums, k, numsSize - 1);
}
