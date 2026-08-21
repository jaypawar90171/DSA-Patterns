#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k)
    {
        int bouquets = 0;
        int flowers = 0;
        for(auto it: bloomDay)
        {
            if(it <= day)
            {
                flowers++;
                if(flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
                flowers = 0; // we only need k adjacnet values if not reset it
        }
        // reason to use > sign is that if more than m bouquets is possible then it is obvious that m is also possible.
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {   
        // impossible to make m bouquets
        long long need = 1LL * m * k;
        if (need > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(canMake(bloomDay, mid, m, k))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,10,3,10,2};
    cout << s.minDays(nums, 3, 2);
}

/*
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/
