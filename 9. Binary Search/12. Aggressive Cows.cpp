#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // helper function check whether with current guess is it possible stall all cows
    bool canPlace(vector<int> &arr, int guess, int &k)
    {
        // first cow is placed at 0th index(why to west it)
        int cows = 1;
        int prev = arr[0]; // indicate location of prev cow
        
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] - prev >= guess)
            {
                cows++;
                prev = arr[i];
                
                if(cows == k)
                    return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) 
    {
        // we need to find minimum distance between any two cows is maximized.
        // i.e minimum distnace between any two adjancent cows is gerater than or equal 
        // to ans, and out of all possible solution need to return the maximum possible ans.
        
        sort(arr.begin(), arr.end()); // array must be sorted
        int ans = 0;
      
        int low = 1;
        int high = arr.back() - arr.front();

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            
            // if any i can be answer then there may chance that further answer is also possible
            if(canPlace(arr, guess, k))
            {
                ans = max(ans, guess);
                low = guess + 1;
            }
            else
            {
                high = guess - 1;
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 1, 2, 7, 5};
    cout << s.aggressiveCows(nums, 3);
}

/*
Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.
Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

Examples:

Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
*/