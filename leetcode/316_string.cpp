#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace testing;

class Solution {
public:
    std::string removeDuplicatedLetters(std::string s)
    {
        if (s.size() <= 1) {
            return s;
        }

        std::array<char, 26> visited{0};
        std::array<char, 26> remain{0};

        for (auto c : s) {
            ++remain[c - 'a'];
        }

        std::vector<char> charStack{};
        for (auto c : s) {
            auto index{c - 'a'};
            --remain[index];

            if (!visited[index]) {
                while (!charStack.empty() && charStack.back() > c && remain[charStack.back() - 'a'] > 0) {
                    visited[charStack.back() - 'a'] = 0;
                    charStack.pop_back();
                }

                charStack.push_back(c);
                visited[index] = 1;
            }
        }

        return {charStack.begin(), charStack.end()};
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().removeDuplicatedLetters("bcabc"), "abc");
    EXPECT_EQ(Solution().removeDuplicatedLetters("cbacdcbc"), "acdb");
}
