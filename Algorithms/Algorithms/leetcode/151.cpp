/*
 Reverse Words in a String

Given an input string, reverse the string word by word.
 
Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string reverseWords(string s)
    {
        int end = s.size();
        string res = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                if (i == 0){
                    for(auto j = i; j<end; j++)
                        res.push_back(s[j]);
                    res.push_back(' ');
                }
            }
            else if (i < end - 1)
            {
                for(auto j = i+1; j<end; j++)
                    res.push_back(s[j]);
                res.push_back(' ');
                end = i;
            }
            else
                end--;
        }
        if (res.size()>0)
            res.pop_back();
        return res;
    }
};

int main()
{
    string s = "the sky  is blue";
    cout << Solution().reverseWords(s) << "\n";
}