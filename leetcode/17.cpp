/*
 Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		const vector<string> letter_map = { "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> old = { "" };
		vector<string> new_;
		for (auto& dig : digits) {
			for (auto& s : old) {
				for (auto& c : letter_map[dig-'0']) {
					new_.push_back(s + c);
				}
			}
			old = move(new_);
		}
		return old;
	}
};

int main() {
	string s = "23";
	auto res = Solution().letterCombinations(s);
	for_each(res.begin(), res.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}