#include "gtest/gtest.h"

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, const std::vector<int>& nums)
    {
        auto size{nums.size()};
        if (size == 0) {
            return 0;
        }

        auto totalSum{0};
        auto minDistance{INT_MAX};
        auto begin{0};
        auto end{0};

        while (end < size) {
            totalSum += nums[end++];
            while (totalSum >= s && begin < end) {
                totalSum -= nums[begin++];
                minDistance = end - begin + 1 < minDistance ? end - begin + 1 : minDistance;
            }
        }

        return minDistance == INT_MAX ? 0 : minDistance;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().minSubArrayLen(7, {2, 3, 1, 2, 4, 3}), 2);
}
