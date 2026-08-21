class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;   
        
        for(int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] <= pq.top()) continue;
            pq.pop();
            pq.push(nums[i]);
        }
    
        return pq.top();
    }
};

int main
{
    Solution s;
    s.findKthLargest({10, 5, 4, 3, 48, 6, 2, 33, 53, 10}, 4)
    return 0;
}