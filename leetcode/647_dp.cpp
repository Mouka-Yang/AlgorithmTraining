#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <vector>
using namespace testing;

class Solution {
public:
    int countSubstring(std::string s)
    {
        if (s.empty()) {
            return 0;
        }

        auto len{s.size()};
        std::vector<std::vector<char>> dp(len, std::vector<char>(len, 0));

        auto count{0U};
        for (int i = len - 1; i >= 0; --i) {
            for (auto j{i}; j < len; ++j) {
                if ((j - i < 2 || dp[i + 1][j - 1]) && s[i] == s[j]) {
                    dp[i][j] = 1;
                    ++count;
                }
            }
        }

        return count;
    }
};

TEST(A, A)
{
    EXPECT_EQ(Solution().countSubstring(""), 0);
    EXPECT_EQ(Solution().countSubstring("abc"), 3);
    EXPECT_EQ(Solution().countSubstring("aaa"), 6);
    EXPECT_EQ(Solution().countSubstring("abbad"), 7);
}
