#include "gtest/gtest.h"

#include <array>
#include <cmath>
#include <vector>

static const std::array<std::array<int, 2>, 8> directions{
    {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c)
    {
        std::vector<std::vector<int>> dp0(N, std::vector<int>(N, 1));

        for (auto k{0}; k < K; ++k) {
            std::vector<std::vector<int>> dp1(N, std::vector<int>(N, 0));
            for (auto i{0}; i < N; ++i) {
                for (auto j{0}; j < N; ++j) {
                    for (auto m{0}; m < 8; ++m) {
                        auto nextRow{i + directions[m][0]};
                        auto nextCol{j + directions[m][1]};
                        if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N) {
                            dp1[i][j] += dp0[nextRow][nextCol];
                        }
                    }
                }
            }

            dp0 = dp1;
        }

        return dp0[r][c] / std::pow(8, K);
    }
};

TEST(SolutionTest, Test)
{
    auto s{Solution()};
    EXPECT_EQ(s.knightProbability(3, 2, 0, 0), 0.0625);
}
