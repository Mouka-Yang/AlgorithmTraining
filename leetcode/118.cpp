/*
Pascal's Triangle

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for (int j = 0; j < numRows; j++) {
            res[j].push_back(1);
            if (j == 0)
                continue;
            if (j > 1)
                for (int i = 1; i < j; i++) {
                    res[j].push_back(res[j - 1][i - 1] + res[j - 1][i]);
                }
            res[j].push_back(1);
        }
        for_each(res.begin(), res.end(), [](const auto x) {
            for_each(x.begin(), x.end(), [](const int c) {
                cout << c << ' ';
            });
            cout << "\n";
        });
        return res;
    }
};

int main() {
    Solution().generate(5);
}