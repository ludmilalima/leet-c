#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int curr = 0;
    int ans = 0;
    int flipped = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            if (flipped < k) {
                flipped++;
            } else {
                while (nums[left] != 0)
                    left++;
                left++;
            }
        }
        curr = i - left + 1;
        ans = ans > curr ? ans : curr;
    }
    return ans;
}

int main() {
    int arr[] = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = longestOnes(arr, n, k);
    printf("The longest subarray with at most %d zeros is: %d\n", k, result);
    return 0;
}