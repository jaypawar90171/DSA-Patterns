#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<pair<int, int>> stack;
        int n = temperatures.size();
        vector<int> ans(n);
        ans[n-1] = 0;
        stack.push({temperatures[n-1], n-1});

        for(int i = n-2; i >= 0; i--)    
        {
            // If stack becomes empty then there is no possible answer for it
            if(stack.empty()) ans[i] = 0;

            while(!stack.empty() && stack.top().first <= temperatures[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                int v1 = stack.top().second;
                int v2 = i;
                ans[i] = v1 - v2;
            }
            stack.push({temperatures[i], i});
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {73,74,75,71,69,72,76,73};
    vector<int> res = s.dailyTemperatures(nums1);
    for(size_t i = 0; i < res.size(); ++i) {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/