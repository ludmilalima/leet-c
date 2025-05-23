#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));

    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++ ) {
        result[i] = result[i - 1] + nums[i];
    }

    return result;
}

int main() {
    int nums[] = {3,1,2,10,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = runningSum(nums, numsSize, &returnSize);
    printf("Running sum: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);

    return 0;
}