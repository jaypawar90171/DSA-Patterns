#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int, int>> projects;
        priority_queue<int> pq;
        for(int i = 0; i < profits.size(); i++)
        {
            projects.push_back({capital[i], profits[i]});
        }    

        sort(projects.begin(), projects.end());

        int index = 0;

        for(int i = 0; i < k; i++)
        {
            // Add all currently affordable projects
            while(index < projects.size() && w >= projects[index].first)
            {
                pq.push(projects[index].second);
                index++;
            }

            // No project can be selected
            if(pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

int main()
{
    Solution s;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0, 1, 1};
    s.findMaximizedCapital(2, 0, profits, capital);
    return 0;
}