#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n = num.length();
        string ans = "";
        if (n == k) return "0";
        stack<int> stack;
        stack.push(num[0] - '0');

        for(int i = 1; i < n; i++)
        {
            while(!stack.empty() && stack.top() > (num[i] - '0') && k > 0)
            {
                stack.pop();
                k--;
            }
            stack.push(num[i] - '0');
        }

        // If k is still left, remove from the end
        while (k > 0)
        {
            stack.pop();
            k--;
        }

        while(!stack.empty())
        {
            ans += stack.top() + '0';
            stack.pop();
        }

        reverse(ans.begin(), ans.end());
        ans.erase(0, ans.find_first_not_of('0')); //remove leading zeros
        if (ans.empty()) return "0";

        return ans;    
    }
};

int main()
{
    Solution s;
    string str = "1432219";
    int k = 3;
    cout << s.removeKdigits(str, k);
}

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/

