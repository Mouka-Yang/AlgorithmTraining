/*
Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char,int> ch_map;
		auto start = 0, end = 0, max = 0;
		for (auto i = 0; i < s.size(); i++) {
			if (ch_map.count(s[i]))
				start = ch_map[s[i]] + 1 > start ? ch_map[s[i]] + 1 : start;
			max = max < i + 1 - start ? i + 1 - start : max;
			ch_map[s[i]] = i;
		}
		return max;
	}
};

int main() {
	string s = "tmmzuxt";
	cout << Solution().lengthOfLongestSubstring(s) << endl;
}