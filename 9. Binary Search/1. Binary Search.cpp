#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0, end = n-1;

        while(low <= end)
        {
            int mid = low + (end - low) / 2;
            cout<<mid<<endl;

            if(nums[mid] == target) return mid;

            if(nums[mid] > target) end = mid - 1;
            else
            {
                low = mid + 1;
            }
        }    
        
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(nums, target);
}