#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& citations, int hIndex)
    {
        int count = 0;
        for(auto it: citations)
        {
            if(it >= hIndex) count++;
        }

        return count >= hIndex;
    }
    int hIndex(vector<int>& citations) 
    {
        int low = 0; // The H-index can be 0 even if the minimum citation is larger, and it can never exceed n (number of papers).
        int high = *max_element(citations.begin(), citations.end());
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(solve(citations, mid))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1,3,5,6};
    cout << s.hIndex(nums);
}