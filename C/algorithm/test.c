//
// Created by fox on 2020/10/9.
//
#include <stdio.h>
#include <malloc.h>
#define MAX(X,Y) ((X) > (Y)) ? (X) : (Y)
#include <fcntl.h> // for open
#include <unistd.h> // for close

int main() {
    int nums[6] = {-2,1,-3,4,-1,2,1,-5,4};
    int max;
     max = maxSubArray1(nums, 9);
    printf("%d",max);
}


int maxSubArray1(int* nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];
    int max = 0;
    for(int i = 1; i< numsSize; i++)
    {
        dp[i] = MAX(nums[i], nums[i] + dp[i-1]);
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}
