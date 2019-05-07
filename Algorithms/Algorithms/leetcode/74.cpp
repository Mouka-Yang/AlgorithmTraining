/*
Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous
row. Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m * n - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            int midVal = matrix[mid / n][mid % n];
            if (midVal == target) {
                return true;
            } else if (midVal > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return false;
    }
};