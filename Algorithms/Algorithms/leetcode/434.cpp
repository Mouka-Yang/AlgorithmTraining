/*
Number of Segments in a String

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int countSegments(string s)
    {
        int count = 0;
        bool check = false;
        for (const char c : s)
        {
            if (c != ' ')
            {
                if (!check)
                {
                    count++;
                    check = true;
                }
            }
            else
                check = false;
        }
    
        return count;
    }
};

int main(){
    string s = "Hello, my name is John";
    cout << Solution().countSegments(s) << endl;
}