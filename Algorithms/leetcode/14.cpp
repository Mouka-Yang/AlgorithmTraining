/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		auto i = 0;
		auto done = false;
		while (i < strs[0].size()) {
			auto c = strs[0][i];
			cout << c << endl;
			for (auto it = strs.begin() + 1; it != strs.end(); it++) {
				if (i >= (*it).size() || (*it)[i] != c) {
					done = true;
					break;
				}
			}
			if (done)	break;

			cout << strs[0].substr(0,i) << endl;
			i++;
		}
		return strs[0].substr(0,i);
	}
};

int main() {
	vector<string> s = { "flower","flow","flight" };
	cout << Solution().longestCommonPrefix(s) << endl;
}