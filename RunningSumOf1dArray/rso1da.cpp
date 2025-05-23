#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> result(numsSize);
        
        result[0] = nums[0];
        for (int i = 1; i < numsSize; i++){
            result[i] = result[i-1] + nums[i];
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.runningSum(nums);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}