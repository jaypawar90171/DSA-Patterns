#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator() (pair<int, int> &a, pair<int, int> &b)
        {
            if(a.second != b.second) return a.second < b.second; //max heap
            return a.first < b.first; //max heap
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // max heap

        for (int row = 0; row < n; row++) 
        {
            int ones = 0;
            for (int col = 0; col < m; col++) 
            {
                ones += mat[row][col];      // adds 1 for each 1, 0 for each 0
            }
            
            if(pq.size() < k)
            {
                pq.push({row, ones});
            }
            else if (ones < pq.top().second || (ones == pq.top().second && row < pq.top().first)) 
            {
                pq.pop();
                pq.push({row, ones});
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

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    int k = 3;
    vector<int> ans = s.kWeakestRows(mat, k);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}