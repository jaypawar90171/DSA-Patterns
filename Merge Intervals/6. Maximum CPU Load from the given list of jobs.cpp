#include <bits/stdc++.h>
using namespace std;

int maxCpuLoad(vector<vector<int>> &list)
{
    vector<pair<pair<int, int>, bool>> jobs;
    int count = 0; // count will contain the count of current loads
    int result = 0; // result will contain maximum of all counts
    int n = list.size();
    
    for(int i = 0; i < n; i++)
    {
        jobs.push_back({{list[i][0], list[i][2]}, true});
        jobs.push_back({{list[i][1], list[i][2]}, false});
    }
    
    sort(jobs.begin(), jobs.end());
    for(auto &job: jobs)
    {
        // if it is a starting job add it loads 
        if(job.second == true)
        {
            count += job.first.second;
            result = max(result, count);
        }
        // if it the ending job remove its load
        else{
            count -= job.first.second;
        }
    }
    return result;
}
int main() {
    vector<vector<int>> list = {
       {1,10,5},
     {2,3,4},
     {4,5,6},
     {6,8,3}
    };
    cout << maxCpuLoad(list);
    return 0;
}
