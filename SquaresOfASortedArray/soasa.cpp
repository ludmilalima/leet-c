#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquaresMemory(vector<int> &nums)
    {
        int right = nums.size() - 1;

        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        while (0 <= right)
        {
            if (abs(nums[0]) > abs(nums[right]))
            {
                nums.insert(nums.begin() + right + 1, nums[0] * nums[0]);
                nums.erase(nums.begin());
                right--;
            }
            else
            {
                nums[right] = nums[right] * nums[right];
                right--;
            }
        }

        return move(nums);
    }

    vector<int> sortedSquaresTime(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        int biggerIndex = 0;
        vector<int> result(nums.size());

        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        while (left <= right)
        {
            biggerIndex = abs(nums[left]) >= abs(nums[right]) ? left++ : right--;
            result[index] = nums[biggerIndex] * nums[biggerIndex];
            index--;
        }

        return move(result);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};

    nums = solution.sortedSquaresTime(nums);
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}