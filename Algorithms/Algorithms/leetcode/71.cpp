/*
Simplify Path
Medium

393

1116

Favorite

Share
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    // string simplifyPath(string path)
    // {
    //     auto start = 1;
    //     vector<string> test;
    //     for (auto i = 1; i < path.size(); i++)
    //     {
    //         if (path[i] == '/' || i == path.size()-1)
    //         {
    //             auto end = path[i] == '/' ? i : i+1;
    //             if (end - 1 >= start)
    //             {

    //                 if (end - start == 2 && path[start] == '.' && path[start + 1] == '.')
    //                 {
    //                     if (test.size() > 0)
    //                         test.pop_back();
    //                 }
    //                 else if (end - start != 1 || path[start] != '.')
    //                 {
    //                     test.push_back(path.substr(start, end-start));
    //                 }
    //             }
    //             start = end + 1;

    //         }
            
            
    //     }

    //     if (test.size() == 0) return "/";

    //     string res = "";
    //     for (auto &x : test)
    //     {
    //         res += "/";
    //         res += x;

    //     }
    //     return res;
    // }

    string simplifyPath(string path)
    {
        auto start = 1;
        vector<int> test(path.size());
        for (auto i = 1; i < path.size(); i++)
        {
            if (path[i] == '/' || i == path.size()-1)
            {
                auto end = path[i] == '/' ? i : i+1;
                if (end - 1 >= start)
                {

                    if (end - start == 2 && path[start] == '.' && path[start + 1] == '.')
                    {
                        if (test.size() > 0)
                            test.pop_back();
                    }
                    else if (end - start != 1 || path[start] != '.')
                    {
                        test.push_back(path.substr(start, end-start));
                    }
                }
                start = end + 1;

            }
            
            
        }

        if (test.size() == 0) return "/";

        string res = "";
        for (auto &x : test)
        {
            res += "/";
            res += x;

        }
        return res;
    }
};

int main()
{
    // string s = "/a//b////c/d//././/..";
    string s = "/home/";
    // string s = "/dir1/.././//dir2/..//dir3/";
    cout << Solution().simplifyPath(s) << "\n";
}