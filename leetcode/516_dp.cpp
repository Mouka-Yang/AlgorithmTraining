#include "gtest/gtest.h"

#include <cstdint>
#include <string>

class Solution {
public:
    int longestPalindromeSubseq(std::string s)
    {
        auto len{static_cast<int>(s.size())};
        std::vector<std::vector<uint8_t>> dp(len, std::vector<uint8_t>(len, 0));

        for (auto i{len - 1}; i >= 0; --i) {
            for (auto j{i}; j < len; ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][len - 1];
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().longestPalindromeSubseq("bbbab"), 4);
    EXPECT_EQ(Solution().longestPalindromeSubseq("cbbd"), 2);
}
