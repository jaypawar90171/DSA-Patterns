#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> map;
        for(auto ch: s)
        {
            map[ch]++;
        }    

        int ans = 0;
        bool hasOdd = false;
        for(auto it: map)
        {
            ans += (it.second / 2) * 2;  // for example like s = "CCC" we need to first divide by 2 and then mul
            if(it.second % 2 != 0) hasOdd = true;
        }

        if(hasOdd) ans += 1;
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "ccc";
    cout << s.longestPalindrome(str);
}

/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
*/