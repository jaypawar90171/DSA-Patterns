#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator() (pair<int, int> &a, pair<int, int> &b)
        {
            if(a.second != b.second) return a.second > b.second; // smaller second has higher priority
            return a.first > b.first; // smaller first has higher priority
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, // <count, number>
            cmp // custom comparison function/struct
        > pq;
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }

        for(auto &[num, count]: mp)
        {
            if(pq.size() < k)
            {
                pq.push({num, count});
            }
            else if (pq.top().second < count)
            {
                pq.pop();
                pq.push({num, count});
            }
        }

        vector<int> ans;
        int count = k;
        while(count != 0)
        {
            int ele = pq.top().first;
            ans.push_back(ele);
            pq.pop();
            count--;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = s.topKFrequent(nums, k);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

TC: O(nlogk)
SC: O(n) + O(k) ~ O(n)
*/