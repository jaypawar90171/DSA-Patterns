#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) 
    {
        priority_queue<pair<int, char>> pq; //max heap
        unordered_map<char, int> freq; // stores frequency

        // Step 1: Mark frequency of each character
        for(auto ch: s)
        {
            freq[ch]++;
        }

        // Step 2: Add all elements form the map to heap
        for(auto &[ch, num]: freq)
        {
            pq.push({num, ch});
        }

        // Step 3: Take a heap top otherwise forced character and add it to answer until heap is not empty.
        string ans = "";
        while(!pq.empty())
        {
            pair<int, char> p = pq.top();
            pq.pop();

            // either ans is empty or it doesn't same as prev character add it to answer 
            if(ans.length() == 0 || ans.back() != p.second)
            {
                ans += p.second;
                p.first--;

                if(p.first > 0) pq.push(p);
            }
            else
            {
                // if after taking first element out and it doesn't match at that particular postion and also heap becomes empty then we cannot build answer
                if(pq.empty()) return "";

                pair<int, char> s = pq.top();
                pq.pop();
                ans += s.second;
                s.first--;
                if(s.first > 0) pq.push(s);

                // IMP: We have to push that taken out element back in heap
                if(p.first > 0) pq.push(p);
            }
        }
        return ans;    
    }
};

int main()
{
    Solution s;
    s.reorganizeString("aab");
    return 0;
}