#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <vector>

struct Lis {
    int min;
    int max;
    int count;
};

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }

        auto len{nums.size()};

        std::vector<uint> dp(len, 0);

        dp[0] = 1U;
        auto maxSeq = 0U;
        for (auto i{1}; i < len; ++i) {
            for (auto j{0}; j < i; ++j) {
                auto currMaxSeq = nums[i] > nums[j] ? dp[j] + 1 : 1U;
                dp[i] = std::max(dp[i], currMaxSeq);
            }
            maxSeq = std::max(maxSeq, dp[i]);
        }

        return maxSeq;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().lengthOfLIS({2, 5, 3, 7}), 3);
    EXPECT_EQ(Solution().lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}), 4);
    EXPECT_EQ(Solution().lengthOfLIS({1, 3, 6, 7, 9, 4, 10, 5, 6}), 6);
}
