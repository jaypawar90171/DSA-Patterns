#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tells how many numbers are less then equal to guess
    int checkCount(int guess, vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int startRow = rows - 1;
        int startCol = 0;

        int count = 0;

        while (startRow >= 0 && startCol < cols) 
        {
            if(matrix[startRow][startCol] <= guess)
            {
                count += startRow + 1;
                startCol++;
            }
            else if(matrix[startRow][startCol] > guess)
            {
                startRow--;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[rows-1][cols-1];

        while(low < high)
        {
            int guess = low + (high - low) / 2;

            int cnt = checkCount(guess, matrix);

            if(cnt < k)
                //if we get coung less than k means we need to check for higher number
                low = guess + 1;
            else
                //check for lower number
                high = guess;
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {{1,5,9},{10,11,13},{12, 13, 15}};
    cout << s.kthSmallest(nums, 8);
}