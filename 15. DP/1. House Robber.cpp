#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, vector<int> &dp, vector<int> &nums)
    {
        //if we come at index 0 then we must have to take it
        if(index == 0) return nums[0];
        else if(index < 0) return 0;  // terminate condition

        if(dp[index] != -1) return dp[index];

        int notTake = 0 + solve(index-1, dp, nums);
        int take = nums[index] + solve(index-2, dp, nums);

        return dp[index] = max(notTake, take);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(n-1, dp, nums);
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    s.rob(nums);
}