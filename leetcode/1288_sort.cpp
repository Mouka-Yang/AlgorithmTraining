#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>
using namespace testing;

class Solution {
public:
    using IntervalList = std::vector<std::vector<int>>;
    using Interval = std::vector<int>;

    int removeCoveredIntervals(IntervalList& intervals)
    {
        if (intervals.size() <= 1) {
            return intervals.size();
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        auto currEnd{intervals[0][1]};
        auto currStart{intervals[0][0]};
        auto len{intervals.size()};
        auto remain{len};
        for (auto i{1U}; i < len; ++i) {
            if (currEnd >= intervals[i][1]) {
                --remain;
            }
            else {
                if (currStart == intervals[i][0]) {
                    --remain;
                }
                currEnd = intervals[i][1];
                currStart = intervals[i][0];
            }
        }

        return remain;
    }
};

TEST(A, A)
{
    Solution::IntervalList a{{1, 4}, {2, 8}, {3, 6}, {4, 7}, {5, 9}, {6, 9}};
    EXPECT_EQ(Solution().removeCoveredIntervals(a), 3);
}
