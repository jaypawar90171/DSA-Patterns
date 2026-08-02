#include <bits/stdc++.h>
using namespace std;


class Solution {
public: 
    // tells how many numbers are less then equal to guess
    int checkCount(int guess, int m, int n)
    {
        int count = 0;

        for (int row = 1; row <= m; row++)
        {
            count += min(n, guess / row);
            cout<<min(n, guess / row)<<" ";
        }
        cout<endl;

        return count;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int low = 0;
        int high = m*n;

        while(low < high)
        {
            int guess = low + (high - low) / 2;

            int cnt = checkCount(guess, m, n);

            if(cnt < k)
                low = guess + 1;
            else
                high = guess;
        }
        return low;
    }
};

int main()
{
    Solution s;
    cout << s.findKthNumber(2, 3, 6);
}