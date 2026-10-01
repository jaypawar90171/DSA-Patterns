#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        int n = courses.size();  
        int currentTotalTime = 0;

        // we want courses to be sorted by duration, beacuse greedy approach will be choose the course which has the least lastDay compared to the others
        sort(courses.begin(), courses.end(), [](const vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
        {
            int duration = courses[i][0];
            int lastDay = courses[i][1];

            // if cours can be taken without exceeding deadline, simple push it to the queue
            if(currentTotalTime + duration <= lastDay)
            {                
                pq.push(duration);
                currentTotalTime += duration;
            }
            else
            {
                // Replace the longest course if current course is shorter, because we want to mazimize our answewr so it is better to replace highest duration couse with lesser duarion
                if(!pq.empty() && duration < pq.top())
                {
                    currentTotalTime -= pq.top();
                    pq.pop();

                    pq.push(duration);
                    currentTotalTime += duration;
                }
            }
        }

        // the pq size indicates the course we can taken
        return pq.size();  
    }
};

int main()
{
    Solution s;
    vector<vector<int>> courses = {{5, 5}, {2, 6}, {3, 7}};
    s.scheduleCourse(courses);
    return 0;
}