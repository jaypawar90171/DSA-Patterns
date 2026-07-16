#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
        string curr = "";
        stack<string> stack;
        int n = path.length();

        for(char c : path)
        {
            if(c == '/')
            {
                if(curr.empty()) continue;

                if(curr == ".") {

                }

                //for .. remove the last element from stack
                else if(curr == "..")
                {
                    if(!stack.empty()) stack.pop();
                }

                //if we reach here it is either ... or ....
                else
                {
                    stack.push(curr);
                }

                curr.clear();
            }
            else
            {
                curr += c;
            }
        }

        // Process the last component if the path doesn't end with '/'
        if(!curr.empty())
        {
            if(curr == ".") {}

            else if(curr == "..")
            {
                if(!stack.empty()) stack.pop();
            }
            else
            {
                stack.push(curr);
            }
        }

        // Build the answer
        vector<string> dirs;
        while (!stack.empty()) {
            dirs.push_back(stack.top());
            stack.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans = "";
        for(auto ch: dirs)
        {
            ans += "/" + ch;
        }

        if (ans.empty())
            return "/";

        return ans;
    }
};

int main()
{
    Solution s;
    string str = "/.../a/../b/c/../d/./";
    cout<< s.simplifyPath(str);
    return 0;
}

/*
Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).
*/