#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        vector<int> result;
        int size = nums.size();
        long accumulate = 0;
        int left = -1;
        int diff = 0;

        result.resize(size, -1);

        for (int j = 0; j < nums.size(); j++)
        {
            accumulate += nums[j];
            left = j - (2 * k);
            diff = left > 0 ? nums[left - 1] : 0;
            accumulate -= diff;

            if (j - (2 * k) >= 0){
                result[j - k] = floor(accumulate / (2 * k + 1));
                printf("i[%d]: %d\n", j, static_cast<int>(result.at(j - k)));
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> input;

    ifstream infile("input.txt");
    string line;
    if (getline(infile, line)) {
        line.erase(std::remove(line.begin(), line.end(), '['), line.end());
        line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
        line.erase(remove(line.begin(), line.end(), '['), line.end());
        line.erase(remove(line.begin(), line.end(), ']'), line.end());
        // Parse numbers separated by commas
        stringstream ss(line);
        string numStr;
        while (getline(ss, numStr, ',')) {
            if (!numStr.empty())
                input.push_back(stoi(numStr));
        }
    }
    vector<int> result = solution.getAverages(input, 882);
    return 0;
}