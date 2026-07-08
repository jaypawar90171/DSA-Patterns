#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  /*
    A start time means one more room is needed.
    An end time means one room becomes free.
  */
    int minMeetingRooms(vector<int> &start, vector<int> &end) 
    {
          sort(start.begin(), start.end()); 
          sort(end.begin(), end.end());
          
          int rooms = 0, maxRooms = 0;
          int n = start.size();
          int i = 0, j = 0;
          
          while(i < n)
          {
              // if start time is less than endtime means we need a room and move start
              if(start[i] < end[j])
              {
                  rooms++;
                  maxRooms = max(maxRooms, rooms);
                  i++;
              }
              // if not we dont need any room and room is free, move end
              else
              {
                  rooms--;
                  j++;
              }
          }
          return maxRooms;
    }
};

int main()
{
    Solution s;
    vector<int> firstList = {2, 9, 6};
    vector<int> secondList = {4, 12, 10};
    int ans = s.minMeetingRooms(firstList, secondList);

    cout << "Minimum meeting rooms required: " << ans << "\n";

    return 0;
}