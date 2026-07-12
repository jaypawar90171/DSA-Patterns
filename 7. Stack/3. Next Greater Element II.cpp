#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
The first n iterations (when i >= n) are only used to prepare the stack with elements that would appear after wrapping around.
*/
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int> stack;
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 2 * n - 1; i >= 0; i--)
        {
            // Pop the elememnts until bigger one is come
            while(!stack.empty() && stack.top() <= nums[i % n])
            {
                stack.pop();
            }

            // Only when we reach the original indices do we record answers.
            if( i < n)
            {
                if(!stack.empty())
                {
                    ans[i] = stack.top();
                }
            }

            stack.push(nums[i % n]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,3};
    vector<int> res = s.nextGreaterElements(nums);
    for(size_t i = 0; i < res.size(); ++i) {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}
