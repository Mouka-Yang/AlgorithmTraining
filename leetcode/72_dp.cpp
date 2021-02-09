#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::string_view;

constexpr auto MAX_WORD_LEN{500U};

class Solution {
 public:
  static constexpr int minDistanceConst(string_view wordX, string_view wordY) {
    auto sizeX = wordX.size();
    auto sizeY = wordY.size();

    std::array<size_t, MAX_WORD_LEN> pre{};
    std::array<size_t, MAX_WORD_LEN> curr{};
    for (auto i{0U}; i < pre.size(); ++i) {
      pre[i] = i;
    }

    for (auto i{1U}; i <= sizeX; ++i) {
      curr[0] = i;
      for (auto j{1U}; j <= sizeY; ++j) {
        auto substitutionCost{0};
        if (wordX[i - 1] != wordY[j - 1]) {
          substitutionCost = 1;
        }

        curr[j] = std::min(
            {(pre[j] + 1), (curr[j - 1] + 1), (pre[j - 1] + substitutionCost)});
      }

      pre = curr;
    }

    return pre[sizeY];
  }

  int minDistance(string_view wordX, string_view wordY) {
    auto sizeRow{wordX.size() + 1};
    auto sizeCol{wordY.size() + 1};

    std::vector<size_t> pre(sizeCol);
    std::vector<size_t> curr(sizeCol);
    std::iota(pre.begin(), pre.end(), 0);

    for (auto i{1U}; i < sizeRow; ++i) {
      curr[0] = i;
      for (auto j{1U}; j < sizeCol; ++j) {
        auto substitutionCost{0};
        if (wordX[i - 1] != wordY[j - 1]) {
          substitutionCost = 1;
        }

        curr[j] = std::min(
            {(pre[j] + 1), (curr[j - 1] + 1), (pre[j - 1] + substitutionCost)});
      }

      std::swap(pre, curr);
    }

    return pre[sizeCol - 1];
  }
};

TEST(SolutionTest, Test) {
  EXPECT_EQ(Solution().minDistance("horse", "ros"), 3);
  EXPECT_EQ(Solution().minDistance("intention", "execution"), 5);
  EXPECT_EQ(Solution().minDistance("hello", ""), 5);
  EXPECT_EQ(Solution().minDistance("", ""), 0);
  EXPECT_EQ(Solution().minDistance("", "hello"), 5);

  constexpr auto i = Solution::minDistanceConst("hello", "aaaworld");
  if constexpr (i > 1) {
    throw std::bad_alloc();
  }
}
