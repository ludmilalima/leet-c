#include <stdio.h>

int getMax (int a, int b) {
    int sum = b * (-1) + 1;
    return (a > sum) ? a : sum;
}

int minStartValue(int* nums, int numsSize) {
    int currentSum = nums[0];
    int startValue = 1;

    startValue = getMax(startValue, currentSum);


    for (int i = 1; i < numsSize; i++) {
        currentSum += nums[i];
        startValue = getMax(startValue, currentSum);
    }

    return startValue;
}


int main () {
    int nums[] = {1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = minStartValue(nums, numsSize);
    printf("Minimum start value: %d\n", result);

    return 0;
}