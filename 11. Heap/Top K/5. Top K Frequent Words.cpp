#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator() (const pair<string, int> &a, const pair<string, int> &b)
        {
            if(a.second != b.second) return a.second > b.second; // smaller second has higher priority
            return a.first < b.first; // lexicographically larger word is worse
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        priority_queue<
            pair<string, int>, 
            vector<pair<string, int>>, // <string, count>
            cmp
        > pq;
        int n = words.size();

        unordered_map<string, int> mp;
        for(auto it: words)
        {
            mp[it]++;
        }

        for(auto &[num, count]: mp)
        {
            if(pq.size() < k)
            {
                pq.push({num, count});
            }
            else if (pq.top().second < count || (pq.top().second == count && pq.top().first > num))
            {
                pq.pop();
                pq.push({num, count});
            }
        }

        vector<string> ans;
        int count = k;
        while(count != 0)
        {
            string ele = pq.top().first;
            ans.push_back(ele);
            pq.pop();
            count--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "is", "is"};
    int k = 4;
    vector<string> ans = s.topKFrequent(words, k);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}

/*
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
*/