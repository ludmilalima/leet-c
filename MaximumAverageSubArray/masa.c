#include <stdio.h>

double findMaxAverage(int *nums, int numsSize, int k)
{
    double ans = 0;
    int curr = 0;

    if (k >= numsSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            ans += nums[i];
            printf("i: %d\n", i);
            printf("ans: %f\n", ans);
        };
        return ans / numsSize;
    };

    for (int i = 0; i < k; i++)
    {
        ans += nums[i];
        printf("i: %d\n", i);
        printf("ans: %f\n", ans);
    };
    
    curr = ans;

    for (int j = k; j < numsSize; j++)
    {
        curr = curr + nums[j] - nums[j - k];
        if (curr > ans)
            ans = curr;

        printf("j: %d\n", j);
        printf("curr: %d\n", curr);
        printf("ans: %f\n", ans);
    };

    return ans / k;
}

int main()
{
    int nums[] = {9, 7, 3, 5, 6, 2, 0, 8, 1, 9};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 6;
    double result = findMaxAverage(nums, numsSize, k);
    printf("The maximum average subarray of size %d is: %f\n", k, result);
    return 0;
}