#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();    
        int m = matrix[0].size();    

        int startingRow = n-1;
        int startingCol = 0;

        while(startingRow >= 0 && startingCol < m)
        {
            if(matrix[startingRow][startingCol] == target) return true;

            if(matrix[startingRow][startingCol] > target)
            {
                //eliminate row
                startingRow--;
            }
            else
            {
                //eliminate col
                startingCol++;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    cout << s.searchMatrix(nums, 5);
}

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.
*/