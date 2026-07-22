#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
All the elements to the left of inflection point > first element of the array.
All the elements to the right of inflection point < first element of the array.
*/
    int findMin(vector<int>& nums) 
    {
        int n  = nums.size();
        int low = 0, end = n - 1;
        int start = nums[0];

        // edge case: array is already sorted
        if (nums[0] <= nums[n - 1]) return nums[0];

        while (low < end) 
        {
            int mid = low + (end - low) / 2;

            if (nums[mid] >= start)
                low = mid + 1;
            else
                end = mid;
        }
        return nums[low];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << s.findMin(nums);
}