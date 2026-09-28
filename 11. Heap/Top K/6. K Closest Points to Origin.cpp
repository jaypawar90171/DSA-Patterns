#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator() (const pair<pair<int, int>, int> &a, const pair<pair<int,int>, int> &b) const
        {
            if(a.second != b.second) return a.second < b.second; // larger distance has higher priority
            if(a.first.first != b.first.first) return a.first.first > b.first.first;
            return a.first.second > b.first.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        int n = points.size();
        priority_queue<
            pair<pair<int, int>, int>,
            vector<pair<pair<int, int>, int>>,
            cmp
        >pq;

        for(auto it: points)
        {
            int x = it[0];
            int y = it[1];

            // calculate the distlidean distance
            int dist = x * x + y * y;

            // push the distance until size reaches k
            if(pq.size() < k)
            {
                pq.push({{x, y}, dist});
            }
            else
            {
                // if the current element has smaller Eucledian distance than top element remove top
                if(dist < pq.top().second)
                {
                    pq.pop();
                    pq.push({{x, y}, dist});
                }
            }
        }

        vector<vector<int>> ans;
        int count = k;
        while(count != 0)
        {
            pair<int, int> ele = pq.top().first;
            ans.push_back({ele.first, ele.second});
            pq.pop();
            count--;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    vector<vector<int>> ans = s.kClosest(points, k);
    for(auto it: ans)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}