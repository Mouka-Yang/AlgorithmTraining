/*
Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;

        while (x <= m - 1 && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                x++;
            } else {
                y--;
            }
        }
        return false;
    }
};