#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int> &arr, int guess, int parts)
    {
        int partCount = 1;
        int partSum = 0;

        for(auto it: arr)
        {
            if(it + partSum > guess)
            {
                partCount++;
                partSum = it;
            }
            else
            {
                partSum += it;
            }
        }
        return partCount <= parts;
    }
    int splitArray(vector<int>& nums, int k) 
    {
        int ans = 0;
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            
            if(canPlace(nums, guess, k))
            {
                ans = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }
        
        return ans;    
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7,2,5,10,8};
    cout << s.splitArray(nums, 2);
}

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/