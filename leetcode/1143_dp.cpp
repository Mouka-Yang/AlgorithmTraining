#include "gtest/gtest.h"

#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2)
    {
        auto size1{text1.size()};
        auto size2{text2.size()};

        std::vector<std::vector<uint16_t>> dp(size1 + 1, std::vector<uint16_t>(size2 + 1, 0));

        for (auto i{1U}; i <= size1; ++i) {
            for (auto j{1U}; j <= size2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[size1][size2];
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().longestCommonSubsequence("abcde", "ace"), 3);
    EXPECT_EQ(Solution().longestCommonSubsequence("abc", "ace"), 2);
}
