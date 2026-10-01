#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;

        for(auto ch : tasks)
            freq[ch]++;

        for(auto &[ch, num] : freq)
            pq.push({num, ch});

        int ans = 0;

        while(!pq.empty())
        {
            int requiredCount = n + 1;
            vector<pair<int, char>> temp;
            int count = 0;

            // Process one complete cycle
            while(count < requiredCount && !pq.empty())
            {
                auto a = pq.top();
                pq.pop();

                a.first--;

                if(a.first > 0)
                    temp.push_back(a);

                count++;
            }

            // Put tasks back ONLY after the cycle is complete
            for(auto &a : temp)
                pq.push(a);

            // Last cycle doesn't need idle time
            if(pq.empty())
                ans += count;
            else
                ans += requiredCount;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    s.leastInterval(tasks, 2);
    return 0;
}