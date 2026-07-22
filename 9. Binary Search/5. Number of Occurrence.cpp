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
    int countFreq(vector<int>& arr, int target) 
    {   
        int last = lastOccurance(arr, target) ;
        int first = firstOccurance(arr, target);
        
        // edge case
        if(first == -1 && last == -1) return 0;
        if(first == last) return 1;
        
        return last - first + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {8, 9, 10, 12, 12, 12};
    cout << s.countFreq(nums, 12);
}
