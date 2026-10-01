#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Note that first for loop onlt tells us thaty how many stations we can reach, not the final target
now, again we need to loop to check whether we actully reach target, with fuel that we taken in first loop
*/
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> pq;
        int reach = startFuel; // maximum distance we can currently reach
        int ans = 0;

        for(auto &station: stations)
        {
            auto position = station[0];
            auto fuel = station[1];

            // if we cannot reach the destionation use privoisuly passed station
            while(reach < position)
            {
                if(pq.empty()) return -1;

                //take out the station with most fuel
                int a = pq.top();
                pq.pop();

                reach += a;
                ans++;
            }

            // Now station is reachable.
            pq.push(fuel);
        }

        // After processing all stations, try to reach the target.
        while (reach < target)
        {
            if (pq.empty())
                return -1;

            reach += pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    s.minRefuelStops(100, 10, stations);
    return 0;
}