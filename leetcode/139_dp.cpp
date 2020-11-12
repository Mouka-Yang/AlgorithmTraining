
#include "gtest/gtest.h"

#include <deque>
#include <string>
#include <unordered_set>
#include <vector>
class Solution {
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict)
    {
        std::unordered_set<std::string> wordSet{wordDict.cbegin(), wordDict.cend()};

        auto len{s.size()};
        std::vector<char> dp(len + 1, 0);

        dp[0] = 1;
        for (auto i{1}; i <= len; ++i) {
            for (auto j{0}; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j)) != 0) {
                    dp[i] = 1;
                }
            }
        }

        return dp[len];
    }
};

TEST(SolutionTest, Test)
{
    std::string s{"catsanddog"};
    std::vector<std::string> w{"cats", "dog", "sand", "and", "cat"};
    EXPECT_TRUE(Solution().wordBreak(s, w));
}

TEST(SolutionTest, Test2)
{
    std::string s{"aaaaaaaaaaaaaaaaaaaaaa"};
    std::vector<std::string> w{"aaa", "a"};
    EXPECT_TRUE(Solution().wordBreak(s, w));
}

TEST(SolutionTest, Test3)
{
    std::string s{"catskicatcats"};
    std::vector<std::string> w{"cats", "cat", "dog", "ski"};
    EXPECT_TRUE(Solution().wordBreak(s, w));
}
