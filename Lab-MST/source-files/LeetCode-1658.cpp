#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int sum = 0;

        for (int num : nums) sum += num;

        if (sum == x) return n;

        int target = sum - x;

        int i = 0, currSum = 0, ans = -1;

        for (int j = 0; j < n; j++)
        {
            currSum += nums[j];

            while (i <= j && currSum > target)
            {
                currSum -= nums[i];
                i++;
            }

            if (currSum == target)
                ans = max(ans, j - i + 1);
        }

        if (ans == -1) return -1;
        return n - ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    cout << sol.minOperations(nums, x) << endl;
    return 0;
}