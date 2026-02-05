#include <limits.h>

int comparar(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comparar);
    
    long long produto1 = (long long)nums[numsSize - 1] * 
                         nums[numsSize - 2] * 
                         nums[numsSize - 3];
    
    long long produto2 = (long long)nums[0] * 
                         nums[1] * 
                         nums[numsSize - 1];
    
    return (produto1 > produto2) ? (int)produto1 : (int)produto2;
}
