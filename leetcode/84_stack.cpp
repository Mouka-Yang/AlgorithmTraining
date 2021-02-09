#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    if (heights.size() < 2) {
      return heights.front();
    }

    std::vector<int> s{};
    auto len = heights.size();
    auto maxArea = 0;
    for (auto i = 0; i <= len; ++i) {
      while (!s.empty() && (i == len || heights[i] < heights[s.back()])) {
        auto currHeight = heights[s.back()];
        s.pop_back();

        auto currWidth = s.empty() ? i : i - s.back() - 1;
        maxArea = std::max(maxArea, currHeight * currWidth);
      }

      s.push_back(i);
    }

    return maxArea;
  }
};

TEST(A, A) {
  EXPECT_EQ(Solution().largestRectangleArea({2, 1, 5, 6, 2, 3}), 10);
  EXPECT_EQ(Solution().largestRectangleArea({2, 4}), 4);
}
