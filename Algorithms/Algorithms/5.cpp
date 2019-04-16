/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	void extendPalindrom(string& s, int l, int r, int& max_l, int& max_r) {
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			l--;
			r++;
		}
		r--; l++;
		cout << l << "," << r << endl;
		if (r >= l && r - l + 1 > max_r - max_l + 1) {
			max_r = r;
			max_l = l;
		}
		cout << max_l << "," << max_r << endl;
	}
	string longestPalindrome(string s) {
		if (s.size() == 0) return "";

		auto start = 0, end = 0, len = 0;
		for (auto i = 0; i < s.size() - 1; i++) {
			extendPalindrom(s, i, i, start, end);
			extendPalindrom(s, i, i + 1, start, end);

		}
		return s.substr(start, end - start + 1);

	}

};

int main() {
	string s = "babad";
	cout << Solution().longestPalindrome(s) << endl;
}