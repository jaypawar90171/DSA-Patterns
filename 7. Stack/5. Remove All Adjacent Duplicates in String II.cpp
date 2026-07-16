#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>> stack;
        int n = s.size();
        stack.push({s[0], 1});

        for(int i = 1; i < n; i++)
        {  
            if (stack.empty()) 
            {
                stack.push({s[i], 1});
            }

            else if(stack.top().first != s[i])
            {
                stack.push({s[i], 1});
            }
            else if(!stack.empty() && stack.top().first == s[i] && stack.top().second == k-1)
            {
                stack.pop();
            }
            else if(stack.top().first == s[i])
            {
                int prev = stack.top().second;
                if(!stack.empty()) stack.pop();
                stack.push({s[i], prev+1});
            }
        }

        string ans = "";
        while(!stack.empty())
        {
            ans.append(stack.top().second, stack.top().first);
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "deeedbbcccbdaa";
    int k = 3;
    cout<< s.removeDuplicates(str, k);
    return 0;
}

/*
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
*/