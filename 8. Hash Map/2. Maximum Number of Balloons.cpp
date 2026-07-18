#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> map;
        for(auto ch: text)
        {
            map[ch]++;
        }
        return min({map['b'], map['a'], map['l'] / 2, map['o'] / 2, map['n']});
    }
};

int main()
{
    Solution s;
    string num = "loonbalxballpoon";
    cout << s.maxNumberOfBalloons(num);
}

/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.
*/