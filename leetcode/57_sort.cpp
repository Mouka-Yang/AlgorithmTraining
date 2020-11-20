#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>
using namespace testing;

class Solution {
public:
    using ResultType = std::vector<std::vector<int>>;
    using IntervalType = std::vector<int>;

    ResultType insert(ResultType& intervals, const IntervalType& newInterval)
    {
        if (intervals.empty()) {
            return {newInterval};
        }

        intervals.push_back(newInterval);

        std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        ResultType res{};
        auto currStart = intervals[0][0];
        auto currEnd = intervals[0][1];
        for (auto i{1U}; i < intervals.size(); ++i) {
            if (currEnd >= intervals[i][0]) {
                currEnd = std::max(currEnd, intervals[i][1]);
            }
            else {
                res.push_back({currStart, currEnd});
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
        }
        res.push_back({currStart, currEnd});

        return res;
    }
};

TEST(A, A)
{
    Solution::ResultType input1{{1, 3}, {6, 9}};
    Solution::ResultType input2{};
    Solution::ResultType input3{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    EXPECT_EQ(Solution().insert(input1, {2, 5}), Solution::ResultType({{1, 5}, {6, 9}}));
    EXPECT_EQ(Solution().insert(input2, {2, 5}), Solution::ResultType({{2, 5}}));
    EXPECT_EQ(Solution().insert(input3, {4, 8}), Solution::ResultType({{1, 2}, {3, 10}, {12, 16}}));
}
