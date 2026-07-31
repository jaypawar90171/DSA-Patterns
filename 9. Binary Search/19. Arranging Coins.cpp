#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) 
    {
        long long low = 0;
        long long high = n;    
        long long rowsFormed = 0;

        while(low <= high)
        {
            long long guess = low + (high - low) / 2; // assumed number of rows.
            long long target = (guess * (guess + 1)) / 2; //this indicates with current guessed row how many coins does it required

            // if required coins is less find on right
            if(target <= n)
            {
                rowsFormed = guess;
                low = guess + 1;
            }
            // if coins are too much find optimal on left
            else
            {
                high = guess - 1;
            }
        }

        return rowsFormed;
    }
};

int main()
{
    Solution s;
    cout << s.arrangeCoins(5);
}