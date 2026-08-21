class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) 
    {
        priority_queue<int> pq;   // max heap

        for(int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++)
        {
            if(arr[i] >= pq.top()) continue;
            pq.pop();
            pq.push(arr[i]);
        }

        return pq.top();
    }
};

int main
{
    Solution s;
    s.kthSmallest({10, 5, 4, 3, 48, 6, 2, 33, 53, 10}, 4)
    return 0;
}