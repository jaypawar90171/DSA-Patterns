#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOccurance(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0, end = n-1;
        int first = -1;

        while(low <= end)
        {
            int mid = low + (end - low) / 2;

            if(nums[mid] == target)
            {
                first = mid;
                end = mid -1;
            }

            else if(nums[mid] > target) end = mid - 1;
            else
            {
                low = mid + 1;
            }
        }    
        
        return first;
    }

    int lastOccurance(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0, end = n-1;
        int last = -1;

        while(low <= end)
        {
            int mid = low + (end - low) / 2;

            if(nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }

            else if(nums[mid] > target) end = mid - 1;
            else
            {
                low = mid + 1;
            }
        }    
        
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        return {firstOccurance(nums, target), lastOccurance(nums, target)};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    for(auto it: ans)
    {
        cout<< it << ",";
    }
    cout<<endl;
}