#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

typedef std::vector<std::vector<char>> MatrixType;

class Solution {
 public:
  bool isValidRectangle(const MatrixType& m, int sx, int sy, int ex, int ey) {
    for (auto i = sx; i <= ex; ++i) {
      for (auto j = sy; j <= ey; ++j) {
        if (m[i][j] == '0') {
          return false;
        }
      }
    }

    return true;
  }

  int getArea(int sx, int sy, int ex, int ey) {
    return (ex - sx + 1) * (ey - sy + 1);
  }

  int bp(const MatrixType& matrix) {
    if (matrix.empty()) {
      return 0;
    }

    auto row = matrix.size();
    auto col = matrix[0].size();

    auto maxArea = 0;
    for (auto startRow = 0; startRow < row; ++startRow) {
      for (auto startCol = 0; startCol < col; ++startCol) {
        for (auto endRow = startRow; endRow < row; ++endRow) {
          for (auto endCol = startCol; endCol < col; ++endCol) {
            if (isValidRectangle(matrix, startRow, startCol, endRow, endCol)) {
              maxArea = std::max(maxArea,
                                 getArea(startRow, startCol, endRow, endCol));
            }
          }
        }
      }
    }

    return maxArea;
  }

  int dp(const MatrixType& m) {
    auto row = m.size();
    auto col = m[0].size();

    std::vector<int> height(col + 1, 0);
    std::vector<int> s{};
    auto maxArea = 0;

    for (auto i = 0; i < row; ++i) {
      for (auto j = 0; j <= col; ++j) {
        if (j < col) {
          if (m[i][j] == '1') {
            ++height[j];
          } else {
            height[j] = 0;
          }
        }

        while (!s.empty() && height[j] < height[s.back()]) {
          auto top = s.back();
          s.pop_back();

          auto currHeight = height[top];
          auto currWidth = s.empty() ? j : j - s.back() - 1;
          maxArea = std::max(maxArea, currHeight * currWidth);
        }

        s.push_back(j);
      }

      s.clear();
    }

    return maxArea;
  }

  int maximalRectangle(const MatrixType& matrix) { return dp(matrix); }
};

TEST(A, A) {
  MatrixType a = {{'1', '0', '1', '0', '0'},
                  {'1', '0', '1', '1', '1'},
                  {'1', '1', '1', '1', '1'},
                  {'1', '0', '0', '1', '0'}};

  EXPECT_EQ(Solution().maximalRectangle(a), 6);

  MatrixType b = {{'0'}};
  EXPECT_EQ(Solution().maximalRectangle(b), 0);

  MatrixType c = {{'1'}};
  EXPECT_EQ(Solution().maximalRectangle(c), 1);
}
