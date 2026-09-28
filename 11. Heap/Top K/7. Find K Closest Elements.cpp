#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator() (pair<int, int> &a, pair<int, int> &b)
        {
            if(a.second != b.second) return a.second < b.second; //min heap
            return a.first < a.second; //min heap
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, // <num, dist>
            cmp
        > pq;
        int n = arr.size();

        for(auto it: arr)
        {
            int dist = abs(it - x);
            if(pq.size() < k)
            {
                pq.push({it, dist});
            }
            else
            {
                if(dist < pq.top().second)
                {
                    pq.pop();
                    pq.push({it, dist});
                }
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
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;
    vector<int> ans = s.findClosestElements(arr, k, x);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}