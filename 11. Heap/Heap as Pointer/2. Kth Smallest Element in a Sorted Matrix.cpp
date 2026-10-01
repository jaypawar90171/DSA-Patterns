#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int value;
        int row;
        int col;
        
        Node(int value, int row, int col)
        {
            this->value = value;
            this->row = row;
            this->col = col;
        }
};

struct cmp
{
    bool operator() (const Node &a, const Node &b)
    {
        return a.value > b.value;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
         int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<Node, vector<Node>, cmp> pq;
        
        for(int i = 0; i < n; i++)
        {
            pq.push({matrix[i][0], i, 0});
        }
        
        vector<int> res;
        
        while(!pq.empty())
        {
            auto n = pq.top();
            pq.pop();
            
            int v = n.value;
            int row = n.row;
            int col = n.col;
            
            res.push_back(v);
            
            if(col != m-1) pq.push({matrix[row][col+1], row, col+1});
        }

        return res[k-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    s.kthSmallest(mat, 8);
    return 0;
}