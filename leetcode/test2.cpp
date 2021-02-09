#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    int NumberOfMountainSeen(const std::vector<int>& height)
    {
        if (height.size() == 1) {
            return 0;
        }

        auto len{height.size()};
        auto count{0U};
        for (auto i{1U}; i < len; ++i) {
            if (i % 2 != 0) {
                count += findRightHigherMountain(height, i + 1, len - 1, height[i]);
            }
            else {
                count += findLeftHigherMountain(height, 0, i - 1, height[i]);
            }
        }

        return count;
    }

private:
    int findRightHigherMountain(const std::vector<int>& heightList, int left, int right, int height)
    {
        if (left > right) {
            return 0;
        }

        auto count{0U};
        auto currHeight{0};
        for (auto i{left}; i <= right; ++i) {
            if (heightList[i] > currHeight) {
                ++count;
                currHeight = heightList[i];
            }
        }

        return count;
    }

    int findLeftHigherMountain(const std::vector<int>& heightList, int left, int right, int height)
    {
        auto count{0U};
        auto currHeight{0};
        for (auto i{right}; i >= left; --i) {
            if (heightList[i] > currHeight) {
                ++count;
                currHeight = heightList[i];
            }
        }

        return count;
    }
};

TEST(A, A)
{
    EXPECT_EQ(Solution().NumberOfMountainSeen({16, 5, 3, 10, 21, 7}), 8);
    EXPECT_EQ(Solution().NumberOfMountainSeen({1, 3, 4, 4, 2}), 4);
}
