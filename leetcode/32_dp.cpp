#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int longestValidParentheses(const std::string& s) {
    // return implBruteForce(s);
    // return implDp(s);
    // return implTwoPass(s);
    return implDp(s);
  }

  int implBruteForce(const std::string& s) {
    auto strLen = s.size();

    auto maxLen{0};
    for (auto i{0}; i < strLen - 1; ++i) {
      auto left{0};
      auto right{0};
      for (auto j{i}; j < strLen; ++j) {
        if (s[j] == '(') {
          ++left;
        } else {
          ++right;
        }

        if (right > left) {
          break;
        }

        if (right == left) {
          maxLen = std::max(maxLen, j - i + 1);
        }
      }
    }

    return maxLen;
  }

  int implTwoPass(const std::string& s) {
    auto len = s.size();

    auto left = 0;
    auto right = 0;
    auto maxLen = 0;
    std::for_each(std::cbegin(s), std::cend(s),
                  [&left, &right, &maxLen](const char c) {
                    if (c == '(') {
                      ++left;
                    } else {
                      ++right;
                    }

                    if (left == right) {
                      maxLen = std::max(maxLen, left * 2);
                    } else if (left < right) {
                      left = 0;
                      right = 0;
                    }
                  });

    left = 0;
    right = 0;
    std::for_each(std::crbegin(s), std::crend(s),
                  [&left, &right, &maxLen](const char c) {
                    if (c == '(') {
                      ++left;
                    } else {
                      ++right;
                    }

                    if (left == right) {
                      maxLen = std::max(maxLen, left * 2);
                    } else if (left > right) {
                      left = 0;
                      right = 0;
                    }
                  });

    return maxLen;
  }

  int implDp(const std::string& s) {
    if (s.size() < 2) {
      return 0;
    }

    auto len = s.size();
    std::vector<int> dp(len + 1, 0);

    auto maxlen = 0;
    for (auto i = 2; i <= len; ++i) {
      if (s[i - 1] == '(') {
        continue;
      }

      if (s[i - 2] == '(') {
        dp[i] = dp[i - 2] + 2;
      } else if (i - 2 - dp[i - 1] >= 0 && s[i - 2 - dp[i - 1]] == '(') {
        dp[i] = dp[i - 1] + dp[i - 2 - dp[i - 1]] + 2;
      }

      maxlen = std::max(maxlen, dp[i]);
    }

    return maxlen;
  }
};
TEST(A, A) {
  EXPECT_EQ(Solution().longestValidParentheses("(()"), 2);
  EXPECT_EQ(Solution().longestValidParentheses("()()"), 4);
  EXPECT_EQ(Solution().longestValidParentheses(")()())"), 4);
  EXPECT_EQ(Solution().longestValidParentheses("(()(()))(()"), 8);
}
