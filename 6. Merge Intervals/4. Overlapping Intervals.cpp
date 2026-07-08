#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        int n = intervals.size();
        int prevStart = 0, prevEnd = 0;
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
            if(i != 0 && start <= prevEnd)
            {
                return true;
            }
            else
            {
                prevStart = start;
                prevEnd = end;
            }
        } 
        return false;
        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {5, 7}, {2, 4}, {6, 8}};
    bool ans = s.isIntersect(intervals);

    cout << "Intervals are overlapping: " << (ans ? "Yes" : "No") << "\n";

    return 0;
}   