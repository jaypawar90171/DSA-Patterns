#include <bits/stdc++.h>
using namespace std;

/*
We have to find out number of shifts to make array sorted rotated
*/
class Solution {
  public:
    int findKRotation(vector<int> &arr) 
    {
        int n  = arr.size();
        int low = 0, end = n - 1;
        int start = arr[0];
        
        // edge case: if array is already sorted
        if(arr[0] <= arr[n-1]) return 0;

        while (low < end) 
        {
            int mid = low + (end - low) / 2;
            
            if(arr[mid] >= start)
            {
                low = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        
        return low - 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 6, 1, 2, 3, 4};
    cout << s.findKRotation(nums);
}
