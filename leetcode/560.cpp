#include "gtest/gtest.h"

#include <map>
#include <vector>

class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k)
    {
        std::map<int, int> sum_map{};
        sum_map[0] = 1;

        auto count{0U};
        auto partialSum{0U};
        for (auto i{0U}; i < nums.size(); i++) {
            partialSum += nums[i];
            if (sum_map.count(partialSum - k) != 0) {
                count += sum_map[partialSum - k];
            }
            sum_map[partialSum] += 1;
        }

        return count;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().subarraySum({1, 2, 3}, 3), 2);
    EXPECT_EQ(Solution().subarraySum({1, 1, 1}, 2), 2);
}
