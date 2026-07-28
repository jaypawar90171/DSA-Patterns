#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool canPlace(vector<int> &arr, int guess, long long k)
    {
        long long  count = 0;
        for(auto it: arr)
        {
            count +=  it / guess;
            if(count >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int ans = 0;
        int low = 1;
        int high = *max_element(candies.begin(), candies.end()); // A child cannot receive more candies than the largest pile.

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            
            // if any i can be answer then there may chance that further answer is also possible
            if(canPlace(candies, guess, k))
            {
                ans = max(ans, guess);
                low = guess + 1;
            }
            else
            {
                high = guess - 1;
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,8,6};
    cout << s.maximumCandies(nums, 3);
}

/*
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
Return the maximum number of candies each child can get.

Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. 
We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. 
It can be proven that each child cannot receive more than 5 candies.
*/