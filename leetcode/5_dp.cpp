#include "gtest/gtest.h"

#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s)
    {
        auto len{static_cast<int>(s.size())};
        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));

        auto resL{0};
        auto resR{0};
        for (int i{len - 1}; i >= 0; --i) {
            for (auto j{i}; j < len; ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                }
                else {
                    if (s[i] == s[j] && (dp[i + 1][j - 1] || j - i < 3)) {
                        dp[i][j] = 1;
                    }
                }

                if (dp[i][j] == 1 && j - i > resR - resL) {
                    resR = j;
                    resL = i;
                }
            }
        }

        return s.substr(resL, resR - resL + 1);
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().longestPalindrome("babad"), "bab");
    EXPECT_EQ(Solution().longestPalindrome("cbbd"), "bb");
}
