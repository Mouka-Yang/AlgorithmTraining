/*
 Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending
multiple copies of the substring together. You may assume the given string consists of lowercase
English letters only and its length will not exceed 10000.

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        auto aa    = std::vector<int>::const_iterator;
        auto len   = s.size();
        bool wrong = false;
        for (auto step = 1; step <= len / 2; step++) {
            if (len % step == 0) {
                for (auto i = 0; i < step; i++) {
                    for (auto j = i; j < len; j += step) {
                        if (s[j] != s[i]) {
                            wrong = true;
                            break;
                        }
                    }
                    if (wrong)
                        break;
                    if (i == step - 1)
                        return true;
                }
            }
        }
    }
};