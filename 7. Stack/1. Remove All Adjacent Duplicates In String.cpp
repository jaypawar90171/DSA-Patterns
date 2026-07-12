#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> stack;
        for(auto &ch: s)
        {
            if(stack.empty())
            {
                stack.push(ch);
            }
            else if(stack.top() == ch)
            {
                stack.pop();
            }
            else if(stack.top() != ch)
            {
                stack.push(ch);
            }
        }

        string ans = "";
        while(!stack.empty())
        {
            ans += stack.top();
            stack.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "abbaca";
    cout << s.removeDuplicates(str);
}