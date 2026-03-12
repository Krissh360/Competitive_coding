#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = -1; 
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            int rem = (k == 0) ? sum : sum % k;
            
            if(mp.count(rem))
            {
                if(i - mp[rem] >= 2) return true;
            }
            else
            {
                mp[rem] = i;
            }
        }
        
        return false;
        
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << sol.checkSubarraySum(nums, k) << endl;
    return 0;
}