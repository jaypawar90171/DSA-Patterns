#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high)
        {
            int mid = low + (high - low) / 2;
            long long hoursTaken = 0;

            for(int i = 0; i < n; i++)
            {
                hoursTaken += ceil((double)piles[i] / mid);
            }   

            if(hoursTaken <= h) high = mid; // found valid answer try to find minimum valid answer
            else
            {
                // we need to decide the new values for the k as it excceds the mentioned hours
                low = mid + 1;
            }
        } 
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {30,11,23,4,20};
    cout << s.minEatingSpeed(nums, 5);
}

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
*/