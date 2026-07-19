#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) 
    {
        int n = arr.size();
        int low = 0, end = n-1;
        int ans = -1;

        while(low <= end)
        {
            int mid = low + (end - low) / 2;
            
            //if we found the element which is greater than tha target, we will mark it as answer
            // but there are chances that, there may be another ele whose samller than current
            // so will move the range find another possible smallest answer
            if(arr[mid] >= x)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int target = 5;
    cout << s.findCeil(arr, target);
}

/*
Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.
Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

Examples
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
Output: 2
Explanation: Smallest number greater than 5 is 8, whose index is 2.
*/