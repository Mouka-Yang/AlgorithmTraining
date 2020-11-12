#include "gtest/gtest.h"

#include <algorithm>
#include <cstddef>
#include <string>

class Solution {
public:
    std::string pushDominoes(std::string dominoes)
    {
        auto len{dominoes.size()};

        auto leftIndex{-1};
        auto leftBorder{'L'};

        dominoes.push_back('R');
        for (auto i{0}; i <= len; ++i) {
            if (dominoes[i] == '.') {
                continue;
            }

            fillDominoes(dominoes, leftIndex, leftBorder, i, dominoes[i]);
            leftIndex = i;
            leftBorder = dominoes[i];
        }

        dominoes.pop_back();
        return dominoes;
    }

    void fillDominoes(std::string& s, int leftIndex, char leftBorder, int rightIndex, char rightBorder)
    {
        if (leftBorder == rightBorder) {
            std::fill(s.begin() + leftIndex + 1, s.begin() + rightIndex, leftBorder);
        }
        else if (leftBorder == 'R' && rightBorder == 'L') {
            auto half{(rightIndex + leftIndex + 1) / 2};

            std::fill(s.begin() + leftIndex + 1, s.begin() + half, 'R');
            std::fill(s.begin() + half, s.begin() + rightIndex, 'L');
            if ((rightIndex - leftIndex + 1) % 2 != 0) {
                s[half] = '.';
            }
        }
    }
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().pushDominoes(".L.R...LR..L.."), "LL.RR.LLRRLL..");
}
