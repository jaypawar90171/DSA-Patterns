#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, end = arr.size() - 1;

        while (low < end) 
        {
            int mid = low + (end - low) / 2;

            // You are on the increasing slope.
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            // ans is either at exactly mid or somewhere left
            else
                end = mid;
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 5, 9, 14, 11, 7, 3, 1};
    cout << s.peakIndexInMountainArray(nums);
}