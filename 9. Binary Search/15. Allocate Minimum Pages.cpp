#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPlace(vector<int> &arr, long long guess, int students)
    {
        long long studentsUsed  = 1; // minimum no of sudents required to maxmimize tha page count to one student
        long long currPages  = 0;
        for(auto w: arr)
        {
            // If adding the next package exceeds the capacity, start a new day.
            if (currPages + w > guess)
            {
                studentsUsed++;
                currPages  = w;
            }
            else
            {
                currPages += w;
            }
        }
        //If the minimum required is 2 and you have 3 students, you can always split one of the contiguous groups into two groups, 
        //as long as every student gets at least one book.
        return studentsUsed <= students;
    } 
    int findPages(vector<int> &arr, int k) 
    {
        long long ans = -1;
        long long low = *max_element(arr.begin(), arr.end()); 
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        
        //edge case
        if (k > arr.size()) return -1;

        while(low <= high)
        {
            long long guess = low + (high - low) / 2;
            
            if(canPlace(arr, guess, k))
            {
                // if we found the answer try to look for minimum in left
                ans = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }
        
        return (int)ans;    
    }
};

int main()
{
    Solution s;
    vector<int> nums = {12, 34, 67, 90};
    cout << s.findPages(nums, 2);
}

/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return -1;

Note: Test cases are generated such that the answer always fits in a 32-bit integer.
*/