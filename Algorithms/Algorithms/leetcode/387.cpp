/*
First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,0);

        for(const char c:s)
            arr[c-'a']++;
        for (auto i = 0; i<s.size(); i++)
            if (arr[s[i]-'a'] == 1)  return i;

        return -1;
    }
};