/*
Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j - 1];
            }
        }
        return dp[n];
    }
};

int main() {
    vector<vector<int>> n{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    Solution().minPathSum(n);
}