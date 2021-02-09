#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

#include <algorithm>
#include <string>
#include <vector>

using std::string_view;

class Solution {
 public:
  int minimumDeleteSumV2(string_view s1, string_view s2) {
    auto size1{s1.size()};
    auto size2{s2.size()};

    std::vector<size_t> pre(size2 + 1, 0);
    std::vector<size_t> curr(size2 + 1, 0);

    for (auto i{1U}; i <= size2; ++i) {
      pre[i] = pre[i - 1] + s2[i - 1];
    }

    for (auto i{1U}; i <= size1; ++i) {
      curr[0] = pre[0] + s1[i - 1];

      for (auto j{1U}; j <= size2; ++j) {
        auto deleteBothCost = 0;
        if (s1[i - 1] != s2[j - 1]) {
          deleteBothCost = s1[i - 1] + s2[j - 1];
        }

        curr[j] = std::min({pre[j - 1] + deleteBothCost,
                            curr[j - 1] + s2[j - 1], pre[j] + s1[i - 1]});
      }

      pre = curr;
    }

    return pre[size2];
  }
  int minimumDeleteSum(string_view s1, string_view s2) {
    auto size1{s1.size()};
    auto size2{s2.size()};

    std::vector<std::vector<size_t>> dp{size1 + 1,
                                        std::vector<size_t>(size2 + 1, 0)};

    for (auto i{1U}; i <= size1; ++i) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (auto i{1U}; i <= size2; ++i) {
      dp[0][i] = dp[0][i - 1] + s2[i - 1];
    }

    for (auto i{1U}; i <= size1; ++i) {
      for (auto j{1U}; j <= size2; ++j) {
        auto deleteBothCost = 0;
        if (s1[i - 1] != s2[j - 1]) {
          deleteBothCost = s1[i - 1] + s2[j - 1];
        }

        dp[i][j] = std::min({dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1],
                             dp[i - 1][j - 1] + deleteBothCost});
      }
    }

    return dp[size1][size2];
  }
};

TEST(SolutionTest, Test) {
  EXPECT_EQ(Solution().minimumDeleteSum("sea", "eat"), 231);
  EXPECT_EQ(Solution().minimumDeleteSum("delete", "leet"), 403);
}
