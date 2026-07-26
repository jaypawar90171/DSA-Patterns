#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n  = nums.size();
        int low = 0, end = n - 1;

        while (low <= end) 
        {
            int mid = low + (end - low) / 2;

            if(nums[mid] == target) return mid;

            else if (nums[low] <= nums[mid]) // left half is sorted
            {
                if(target >= nums[low] && target < nums[mid]) end = mid - 1;
                else
                    low = mid + 1;
            }
            else  // right half is sorted
            {
                if(target > nums[mid] && target <= nums[end]) low = mid + 1;
                else    
                    end = mid - 1;
            }
        }
        return -1;    
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << s.search(nums, 0);
}