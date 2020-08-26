/*
Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the
matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};

        int m = matrix.size(), n = matrix[0].size();
        int loopCount = (min(m, n) + 1) / 2;

        vector<int> res(m * n);
        int count = 0;
        for (int loop = 0; loop < loopCount; loop++) {
            for (int i = loop; i < n - loop; i++) {
                res[count++] = matrix[loop][i];
            }
            for (int j = loop + 1; j < m - loop; j++) {
                res[count++] = matrix[j][n - 1 - loop];
            }
            if (loop < min(m, n) - 1 - loop) {
                for (int i = n - 2 - loop; i >= loop; i--) {
                    res[count++] = matrix[m - 1 - loop][i];
                }
                for (int j = m - 2 - loop; j >= loop + 1; j--) {
                    res[count++] = matrix[j][loop];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> n{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution().spiralOrder(n);
}