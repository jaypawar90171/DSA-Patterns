#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        int prevStart = 0, prevEnd = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(i == 0)
            {
                prevStart = start;
                prevEnd = end;
            }
            //otherwise calculate or check if they can merge
            if(start <= prevEnd)
            {
                prevEnd = max(end, prevEnd);
            }
            else
            {
                ans.push_back({prevStart, prevEnd});
                prevStart = start;
                prevEnd = end;
            }
        } 
        ans.push_back({prevStart, prevEnd}); 
        return ans;  
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval);
        return solve(intervals);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> merged = s.insert(intervals, newInterval);

    for (const auto &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << "\n";

    return 0;
}