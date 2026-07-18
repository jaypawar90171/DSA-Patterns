#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};

        for(char c:s)
        {
            count[c-'a'] += 1;
        }

        for(int i=0;i<s.length();i++)
        {
            if(count[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string str = "loveleetcode";
    cout << s.firstUniqChar(str);
}