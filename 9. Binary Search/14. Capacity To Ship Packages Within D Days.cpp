#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int> &arr, int capacity, int days)
    {
        int usedDays = 1;
        int currWeight = 0;
        for(auto w: arr)
        {
            // If adding the next package exceeds the capacity, start a new day.
            if (currWeight + w > capacity)
            {
                usedDays++;
                currWeight = w;
            }
            else
            {
                currWeight += w;
            }
        }
        return usedDays <= days;;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int ans = 0;
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            
            if(canPlace(weights, guess, days))
            {
                // if we found the answer try to look for minimum in left
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
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    cout << s.shipWithinDays(nums, 5);
}

/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/