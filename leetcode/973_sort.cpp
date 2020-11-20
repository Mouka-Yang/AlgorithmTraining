#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <cmath>
#include <vector>
using namespace testing;

class Solution {
public:
    using PointList = std::vector<std::vector<int>>;
    using Point = std::vector<int>;

    PointList kClosest(PointList& points, int K)
    {
        std::sort(points.begin(), points.end(), [this](const auto& lhs, const auto& rhs) {
            return getDistanceToOrigin(lhs) < getDistanceToOrigin(rhs);
        });

        return PointList(points.begin(), points.begin() + K);
    }

    double getDistanceToOrigin(const Point& point)
    {
        return std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));
    }
};

TEST(A, A)
{
    Solution::PointList a{{-5, 4}, {-6, -5}, {4, 6}};
    Solution::PointList b{{-5, 4}, {4, 6}};
    EXPECT_EQ(Solution().kClosest(a, 2), b);
}
