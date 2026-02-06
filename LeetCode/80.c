int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2)
        return numsSize;
    
    int indice = 2;
    
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[indice - 2]) {
            nums[indice] = nums[i];
            indice++;
        }
    }
    
    return indice;
}
