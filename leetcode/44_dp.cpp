#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

using std::string;
class Solution {
 public:
  bool isMatch(const string& s, const string& p) { return isMatch_dp(s, p); }

  bool isMatch_memo(string s, string p) {
    auto pp = stripStar(p);

    std::vector<std::vector<int>> dp(s.size() + 1,
                                     std::vector<int>(pp.size() + 1, -1));
    return submatch(s, 0, pp, 0, dp);
  }

  string stripStar(const string& s) {
    if (s.size() < 2) {
      return s;
    }

    string ret{s.front()};
    for (auto i = 1; i < s.size(); ++i) {
      if (s[i - 1] == '*' && s[i] == '*') {
        continue;
      }

      ret.push_back(s[i]);
    }

    return ret;
  }

  bool submatch(const string& s, size_t si, const string& p, size_t pi,
                std::vector<std::vector<int>>& dp) {
    if (si == s.size()) {
      if (pi == p.size() || ((pi == p.size() - 1) && (p[pi] == '*'))) {
        dp[si][pi] = 1;
      } else {
        dp[si][pi] = 0;
      }
    } else if (s[si] == p[pi] || p[pi] == '?') {
      if (dp[si + 1][pi + 1] == -1) {
        submatch(s, si + 1, p, pi + 1, dp);
      }
      dp[si][pi] = dp[si + 1][pi + 1];
    } else if (p[pi] == '*') {
      if (pi == p.size() - 1) {
        dp[si][pi] = 1;
      } else {
        dp[si][pi] = 0;
        for (auto i = si; i < s.size(); ++i) {
          if (dp[i][pi + 1] == -1) {
            submatch(s, i, p, pi + 1, dp);
          }
          if (dp[i][pi + 1] == 1) {
            dp[si][pi] = 1;
            break;
          }
        }
      }
    } else {
      dp[si][pi] = 0;
    }

    return dp[si][pi];
  }

  bool isMatch_dp(const string& s, const string& p) {
    auto lenS = s.size();
    auto lenP = p.size();
    if (lenS == 0) {
      auto hasOnlyStart = true;
      for (auto c : p) {
        if (c != '*') {
          hasOnlyStart = false;
          break;
        }
      }

      return hasOnlyStart;
    }

    std::vector<std::vector<int>> dp(lenS + 1, std::vector<int>(lenP + 1, 0));
    for (auto i = 0; i < lenP; ++i) {
      dp[lenS][i] = -1;
    }

    for (int i = lenP - 1; i >= 0; --i) {
      for (int j = lenS - 1; j >= 0; --j) {
        if (s[j] == p[i] || p[i] == '?') {
          dp[j][i] = dp[j + 1][i + 1] == lenS - j - 1 ? lenS - j : dp[j + 1][i];
        } else if (p[i] == '*') {
          dp[j][i] = dp[j][i + 1] >= 0 ? lenS - j : -1;
        } else {
          dp[j][i] = dp[j + 1][i];
        }
      }
    }

    return dp[0][0] == lenS;
  }
};

TEST(A, A) {
  //   EXPECT_FALSE(Solution().isMatch("aa", "a"));
  //   EXPECT_TRUE(Solution().isMatch("aa", "*"));
  //   EXPECT_FALSE(Solution().isMatch("cb", "?a"));
  //   EXPECT_TRUE(Solution().isMatch("adceb", "*a*b"));
  EXPECT_FALSE(Solution().isMatch("abcabczzzde", "*abc???de*"));
  //   EXPECT_FALSE(Solution().isMatch("aab", "c*a*b"));
}
