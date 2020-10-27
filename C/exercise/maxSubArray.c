#include <stdio.h>
int main() {
    int nums[9] = {1,4,3,-43,55,6,3,-9,2};
    int max = maxSubArray(nums,9);
    printf("%d",max);
}
int maxSubArray(int* nums, int numsSize) {
    int subSum = 0;
    int maxSum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        subSum += nums[i];
        if (subSum > maxSum)
            maxSum = subSum;
        if (subSum < 0)
            subSum = 0;
    }
    return maxSum;
}