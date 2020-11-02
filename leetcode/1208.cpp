#include <cstddef>
#include <string>
#include <cmath>
#include "gtest/gtest.h"

class Solution{
public:
    size_t static getDistance(char x, char y)
    {
        return std::abs(x - y);
    }
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        auto size{s.size()};
        auto totalCost{0};

        auto i{0U};
        auto j{0U};
        while (j < size) {
            auto currentDistance{getDistance(s[j], t[j])};
            totalCost += currentDistance;
            ++j;

            if (totalCost > maxCost) {
                totalCost -= getDistance(s[i], t[i]);
                i++;
            }
        }

        return j - i;
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().equalSubstring("abcd", "bcdf", 3), 3);
    EXPECT_EQ(Solution().equalSubstring("abcd", "cdef", 3), 1);
    EXPECT_EQ(Solution().equalSubstring("abcd", "acde", 0), 1);
}
