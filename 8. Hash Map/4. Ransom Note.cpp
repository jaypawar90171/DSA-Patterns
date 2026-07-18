#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> map;

        for(auto ch: ransomNote)
        {
            map[ch]++;
        }

        for(auto ch: magazine)
        {
            map[ch]--;
        }

        for(auto it: map)
        {
            if(it.second > 0) return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    string str1 = "a";
    string str2 = "b";
    cout << s.canConstruct(str1, str2);
}

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/