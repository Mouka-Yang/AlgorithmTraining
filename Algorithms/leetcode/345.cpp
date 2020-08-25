/*
Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        int arr[58] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

        while (i < j)
        {
            while (!arr[s[i]-'A'])
                i++;
            while (!arr[s[j]-'A'])
                j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};