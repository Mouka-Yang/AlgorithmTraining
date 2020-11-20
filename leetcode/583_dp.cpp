#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>
#include <vector>
using namespace testing;

class Solution {
public:
    int minDistance(std::string s1, std::string s2)
    {
        auto size1{s1.size()};
        auto size2{s2.size()};
        std::vector<std::vector<size_t>> dp(size1 + 1, std::vector<size_t>(size2 + 1, 0));

        for (auto i{1U}; i <= size1; ++i) {
            for (auto j{1U}; j <= size2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return size1 - dp[size1][size2] + size2 - dp[size1][size2];
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().minDistance("pqrst", "prt"), 2);
}
