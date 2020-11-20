#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>
using namespace testing;

class Solution {
public:
    using BalloonType = std::vector<int>;
    using BalloonListType = std::vector<std::vector<int>>;
    int findMinArrowShots(BalloonListType points)
    {
        if (points.size() <= 1) {
            return points.size();
        }

        std::sort(
            points.begin(), points.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        auto count{1U};
        auto currStart{points[0][0]};
        auto currEnd{points[0][1]};
        for (auto i{1U}; i < points.size(); ++i) {
            if (points[i][0] <= currEnd) {
                currEnd = std::min(currEnd, points[i][1]);
            }
            else {
                ++count;
                currEnd = points[i][1];
            }
        }

        return count;
    }
};

TEST(A, A)
{
    Solution::BalloonListType a1{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution::BalloonListType a2{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    EXPECT_EQ(Solution().findMinArrowShots(a1), 2);
    EXPECT_EQ(Solution().findMinArrowShots(a2), 4);
}
