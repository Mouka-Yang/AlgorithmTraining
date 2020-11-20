#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>
using namespace testing;

class Solution {
public:
    int nextGreaterElement(int n)
    {
        auto numStr{std::to_string(n)};
        if (std::is_sorted(numStr.begin(), numStr.end(), std::greater<char>())) {
            return -1;
        }

        auto found{false};
        for (auto i{1U}; i < numStr.size() && !found; ++i) {
            if (std::is_sorted(numStr.begin() + i, numStr.end(), std::greater<char>())) {
                for (auto j{numStr.size() - 1}; j >= i; --j) {
                    if (numStr[i - 1] < numStr[j]) {
                        std::swap(numStr[i - 1], numStr[j]);
                        std::sort(numStr.begin() + i, numStr.end());
                        found = true;
                        break;
                    }
                }
            }
        }

        auto res = std::stoull(numStr);
        if (res > INT32_MAX) {
            return -1;
        }
        return res;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().nextGreaterElement(32641), 34126);
    EXPECT_EQ(Solution().nextGreaterElement(12345), 12354);
}
