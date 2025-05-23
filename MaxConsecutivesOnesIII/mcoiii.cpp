#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left;
        int ans;
        int flipped;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (flipped < k)
                    flipped++;
                else {
                    while(nums[left] != 0) {
                        left++;
                    }
                    left++;
                }
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int result = sol.longestOnes(arr, k);
    cout << "The longest subarray with at most " << k << " zeros is: " << result << endl;
    return 0;
}