#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <array>
#include <string>
using namespace testing;

class Solution {
public:
    std::string customSortString(std::string s1, std::string s2)
    {
        std::array<char, 26> weight{0};
        auto count{0U};
        for (auto c : s1) {
            weight[c - 'a'] = count++;
        }

        std::sort(s2.begin(), s2.end(), [&weight](const auto& lhs, const auto& rhs) {
            return weight[lhs - 'a'] < weight[rhs - 'a'];
        });

        return s2;
    }
};

TEST(A, A)
{
    EXPECT_EQ(Solution().customSortString("cba", "abcd"), "cbad");
}
