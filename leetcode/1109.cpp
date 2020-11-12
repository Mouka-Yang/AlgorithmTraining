#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(const std::vector<std::vector<int>>& bookings, int n)
    {
        std::vector<int> res(n, 0);

        std::for_each(bookings.cbegin(), bookings.cend(), [&res](const auto& booking) {
            auto start{booking[0] - 1};
            auto end{booking[1]};
            auto num{booking[2]};

            std::for_each(res.begin() + start, res.begin() + end, [num](auto& value) { value += num; });
        });

        return res;
    }
};

TEST(SolutionTest, Test)
{
    std::vector<std::vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};

    EXPECT_EQ(Solution().corpFlightBookings(bookings, 5), std::vector<int>({10, 55, 45, 25, 25}));
}
