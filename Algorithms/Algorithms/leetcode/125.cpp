/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int i = 0, j= s.size()-1;
        while(i < j){
            while(!isalnum(s[i]) && i < j)   i++;
            while(!isalnum(s[j]) && i < j)   j--;
            if (i > j || s[i] != s[j] || abs(s[j]-s[i]) != 'a'-'A' || max(s[i],s[j]) < 'a')   return false;

            i++;j--;
        }
        return true;
    }
};

int main(){
    string s = "0P";
    cout << Solution().isPalindrome(s) << "\n";
}