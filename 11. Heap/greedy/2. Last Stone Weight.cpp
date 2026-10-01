#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        for(auto stone: stones)
        {
            pq.push(stone);
        }

        while(pq.size() >= 2)
        {
            int f = pq.top();
            pq.pop();

            int s = pq.top();
            pq.pop();

            if(f != s)
            {
                int newWeight = abs(f-s);
                pq.push(newWeight);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    Solution s;
    vector<int> stones = {2,7,4,1,8,1};
    s.lastStoneWeight(stones);
    return 0;
}