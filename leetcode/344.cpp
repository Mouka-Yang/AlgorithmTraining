/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        auto len = s.size();
        for (auto i = 0; i < len / 2; i++)
        {
            swap(s[i], s[len - i - 1]);
        }
    }
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    for_each(s.begin(), s.end(), [](const char &x) { cout << x; });
    cout << "\n";
}