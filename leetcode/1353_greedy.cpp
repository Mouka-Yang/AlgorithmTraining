#include "gtest/gtest.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events)
    {
        std::sort(
            events.begin(), events.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        std::sort(
            events.begin(), events.end(), [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });

        std::vector<int> record(100000, 0);

        auto count{0U};
        for (const auto& event : events) {
            for (auto i{event[0]}; i <= event[1]; ++i) {
                if (record[i] == 0) {
                    record[i] = 1;
                    ++count;
                    break;
                }
            }
        }

        return count;
    }
};

TEST(SolutionTest, Test)
{
    // auto res = std::vector<std::vector<int>>{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    auto res = std::vector<std::vector<int>>{{1,2},{2,3},{3,4},{1,2}};
    EXPECT_EQ(Solution().maxEvents(res), 4);
}
