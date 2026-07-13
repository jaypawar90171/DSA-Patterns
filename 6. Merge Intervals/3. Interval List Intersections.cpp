#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            int a1 = firstList[i][0], a2 = firstList[i][1];
            for(int j = 0; j < m; j++)
            {
                int b1 = secondList[j][0], b2 = secondList[j][1];

                int start = max(a1, b1);
                int end = min(a2, b2);

                //start should be less than end to insert
                if(start <= end)
                {
                    ans.push_back({start, end});
                }
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> ans = s.intervalIntersection(firstList, secondList);

    for (const auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << "\n";

    return 0;
}

/*
Example 1:
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/