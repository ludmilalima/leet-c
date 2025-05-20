#include <vector>
#include <stdio.h>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    double ans = 0;
    double curr = 0;

    for (int i = 0; i < k; i++)
    {
        ans += nums[i];
    };

    if (k >= nums.size())
    {
        return ans / nums.size();
    };

    curr = ans;

    for (int j = k; j < nums.size(); j++)
    {
        curr = curr + nums[j] - nums[j - k];
        ans = max(ans, curr);
    };

    return ans / k;
};

int main()
{
    std::vector<int> nums = {9, 7, 3, 5, 6, 2, 0, 8, 1, 9};
    int k = 6;
    double result = findMaxAverage(nums, k);
    printf("The maximum average subarray of size %d is: %f\n", k, result);
    return 0;
}
