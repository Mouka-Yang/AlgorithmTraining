#include "gtest/gtest.h"

#include <algorithm>
#include <unordered_set>
#include <vector>
bool compareEvents(const std::vector<int>& eventX, const std::vector<int>& eventY)
{
    return eventX[1] - eventX[0] < eventY[1] - eventY[0];
}

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events)
    {
        std::sort(events.begin(), events.end(), compareEvents);

        std::unordered_set<int> dayCount{};
        for (const auto& event : events) {
            auto startDay{event[0]};
            auto endDay{event[1]};
            for (auto i{startDay}; i <= endDay; ++i) {
                if (dayCount.count(i) == 0) {
                    dayCount.insert(i);
                    break;
                }
            }
        }

        return dayCount.size();
    }
};

TEST(SolutionTest, Test)
{
    // auto res = std::vector<std::vector<int>>{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    auto res = std::vector<std::vector<int>>{{1,2},{2,3},{3,4},{1,2}};
    EXPECT_EQ(Solution().maxEvents(res), 4);
}
