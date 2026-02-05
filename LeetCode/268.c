int missingNumber(int* nums, int numsSize) {
    int resultado = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        resultado ^= i;
        resultado ^= nums[i];
    }
    
    return resultado;
}
