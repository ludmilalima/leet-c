#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftSubarray(int *arr, int size, int start, int end) {
    if (start < end && end < size) {
        memmove(&arr[start], &arr[start + 1], (end - start) * sizeof(int));
    }
}

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{

    int left = 0;
    int index = numsSize - 1;
    int biggerIndex = 0;
    int biggerValue = 0;

    for ( ; left <= index ; )
    {
        biggerIndex = abs(nums[left]) >= abs(nums[index]) ? left : index;
        biggerValue = nums[biggerIndex] * nums[biggerIndex];
        shiftSubarray(nums, numsSize, biggerIndex, index);
        nums[index] = biggerValue;
        index--;
    }

    *returnSize = numsSize;
    return nums;
}

int main()
{
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    sortedSquares(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}