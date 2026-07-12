#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> map;
        stack<int> stack;

        // Step 1: Find out the next greater element for each element
        for(auto it: nums2)
        {
            while(!stack.empty() && stack.top() < it)
            {
                map[stack.top()] = it;
                stack.pop();
            }
            stack.push(it);
        }  

        //step 2: for the element who have not greater element maek it as -1;
        while(!stack.empty())
        {
            map[stack.top()] = -1;
            stack.pop();
        } 

        for(auto it: map)
        {
            cout<< it.first << "->" << it.second << endl;
        }
        
        // Step 3: Simply lookup in the hashtable for the corresponding entry.
        vector<int> ans;
        for(auto it: nums1)
        {
            ans.push_back(map[it]);
        }

        return ans;
    }
    
};

int main()
{
    Solution s;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for(size_t i = 0; i < res.size(); ++i) {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

/*
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/