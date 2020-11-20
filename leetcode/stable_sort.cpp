#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>
using namespace testing;

TEST(StableSort, Test)
{
    std::vector<std::vector<int>> input{{1, 4}, {3, 4}, {1, 2}, {2, 4}, {2, 6}, {3, 5}, {4, 6}, {5, 7}};

    std::stable_sort(
        input.begin(), input.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

    std::stable_sort(
        input.begin(), input.end(), [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });

    EXPECT_EQ(
        input,
        std::vector<std::vector<int>>({{1, 2}, {1, 4}, {2, 4}, {3, 4}, {3, 5}, {2, 6}, {4, 6}, {5, 7}}));
}
