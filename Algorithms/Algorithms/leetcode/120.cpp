/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		for (auto i = 1; i < triangle.size(); i++) {
			for (auto j = 0; j < triangle[i].size(); j++) {
				if (j == 0)	triangle[i][j] += triangle[i - 1][j];
				else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
				else triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
		return *min_element(triangle.back().begin(), triangle.back().end());
	}
};

int main() {
	vector<vector<int>> t = { {2},{3,4},{6,5,7}, {4,1,8,3} };
	cout << Solution().minimumTotal(t) << endl;
}