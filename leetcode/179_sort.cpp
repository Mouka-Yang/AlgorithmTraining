#include "gtest/gtest.h"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

bool compareNum(int x, int y)
{
    std::uint64_t left = std::stoull(std::to_string(x) + std::to_string(y));
    std::uint64_t right = std::stoull(std::to_string(y) + std::to_string(x));

    return left < right;
}

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end(), compareNum);

        if (nums.back() == 0){

            return "0";
        }

        std::stringstream ss;
        std::for_each(nums.crbegin(), nums.crend(), [&ss](const auto& num) { ss << num; });

        return ss.str();
    }
};

TEST(SolutionTest, Test)
{
    std::vector<int> nums{3, 30, 34, 5, 9};
    EXPECT_EQ(Solution().largestNumber(nums), "9534330");
}
