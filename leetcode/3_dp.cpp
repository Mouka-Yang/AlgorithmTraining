#include <algorithm>
#include <array>
#include <string>
#include <vector>

#include "gtest/gtest.h"
class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    if (s.empty()) {
      return 0;
    }

    std::array<int, 128> used{};
    used.fill(-1);

    auto left = 0;
    auto right = 0;
    auto res = 0;
    while (right < s.size()) {
      auto currChar = s[right];

      if (used[currChar] != -1 && left <= used[currChar]) {
        left = used[currChar] + 1;
      }

      res = std::max(res, right - left + 1);
      used[currChar] = right;
      ++right;
    }

    return res;
  }
};

TEST(A, A) { EXPECT_EQ(Solution().lengthOfLongestSubstring("abcabcbb"), 3); }