/*
 Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size()) return;

        int m = matrix.size(), n = matrix[0].size();
        bool firstColClear = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColClear = true;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (firstColClear) {
            for_each(matrix.begin(), matrix.end(), [](auto& x) {
                x[0] = 0;
            });
        }
    }
};

int main() {
    vector<vector<int>> n{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    Solution().setZeroes(n);
}