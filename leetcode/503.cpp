#include "gtest/gtest.h"
#include "header.h"

// Input [1,2,1]
//  Output [2,-1,2]

class Solution {
public:
    size_t getCyclicIndex(size_t index, const std::vector<int>& nums)
    {
        return index % nums.size();
    }

    int getGreaterElement(size_t index, const std::vector<int>& nums)
    {
        auto numSize = nums.size();
        auto currentIndex = getCyclicIndex(index + 1, nums);
        while (currentIndex != index && nums[currentIndex] <= nums[index]) {
            currentIndex = getCyclicIndex(currentIndex + 1, nums);
        }

        if (currentIndex != index) {
            return nums[currentIndex];
        }
        return -1;
    }
    std::vector<int> nextGreaterElements(const std::vector<int>& nums)
    {
        auto res = std::vector<int>(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            res[i] = getGreaterElement(i, nums);
        }

        return res;
    }
};

TEST(MainTest, GetGreaterElement)
{
    auto res = Solution().nextGreaterElements({1, 2, 1});
    EXPECT_EQ(res, std::vector<int>({2, -1, 2}));
}
