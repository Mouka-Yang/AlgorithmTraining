/*
Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> char_count;
		for (auto& c : s) {
			if (char_count.count(c)) char_count[c]++;
			else char_count[c] = 1;
		}
		auto max = 0;
		auto single = false;
		auto even_count = 0;
		for (auto& p : char_count) {
			cout << p.first << "," << p.second << endl;
			if (p.second % 2 != 0) {
				max += p.second - 1;
				if (!single) {
					single = true;
					max += 1;
				}
			}
			if (p.second % 2 == 0) {
				max += p.second;
			}
			cout << max << endl;
		}
		return max;
	}

	int longestPalindrome3(string s) {
		auto i = 0, max = 0;
		auto single = false;
		vector<int> arr(58, 0);
		for (auto& c : s) {
			arr[c - 'A'] ++;
		}
		for (auto& i : arr) {
			if (i % 2 == 0)
				max += i;
			else {
				max += i - 1;
				single = true;
			}
		}
		return single ? max + 1 : max;
		auto i = (int)'z'
	}

	int longestPalindrome2(string s) {
		auto i = 0,max = 0;
		auto single = false;
		set<char> myset;
		for (auto& c : s) {
			if (myset.count(c)) {
				myset.erase(c);
			}
			else
				myset.emplace(c);
		}
		cout << s.size() << "," << myset.size() << endl;
		return s.size() - myset.size() + (myset.empty() ? 0 : 1);
	}
};

int main() {
	string s = "abccccdd";
	cout << Solution().longestPalindrome3(s) << endl;
}