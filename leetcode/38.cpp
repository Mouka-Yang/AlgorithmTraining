/*
38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		string res = "";
		auto count = 1;
		for (auto x = 0; x < n-1; x++) {
			auto i = 0;
			for (; i < s.size() - 1; i++) {
				if (s[i] == s[i + 1] ) {
					count++;
				}
				else {
					res = res + to_string(count) + s[i];
					count = 1;
				}
			}
			s = res + to_string(count)  + s[i];
			count = 1;

			cout << res << endl;
			res.clear();
		}
		return s;
		
	}
};

int main() {
	cout << Solution().countAndSay(7) << endl;
}