#include "gtest/gtest.h"

#include <algorithm>
#include <array>
#include <deque>
#include <vector>

static constexpr std::array<std::array<int, 2>, 4> moves = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

class Solution {
public:
    using grid_t = std::vector<std::vector<int>>;
    using row_t = std::vector<int>;

    bool isIsland(int row, int col)
    {
        return isValid(row, col) && (*grid)[row][col] == 1;
    }

    bool isValid(int row, int col)
    {
        return row >= 0 && col >= 0 && row < len && col < len;
    }

    bool isWater(int row, int col)
    {
        return isValid(row, col) && !isIsland(row, col);
    }

    void bfs(int row, int col)
    {
        std::deque<std::pair<int, int>> queue{};
        queue.emplace_back(row, col);
        visited[row][col] = 1;

        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop_front();

            for (const auto& move : moves) {
                auto nextRow{row + move[0]};
                auto nextCol{col + move[1]};
                if (!visited[nextRow][nextCol] && isIsland(nextRow, nextCol)) {
                    visited[nextRow][nextCol] = 1;
                    queue.emplace_back(nextRow, nextCol);
                }
            }
        }
    }

    int shortestBridge(const grid_t A)
    {
        len = A.size();
        grid = &A;

        visited = grid_t(len, row_t(len, 0));
        auto first{true};

        auto minRes{10000};
        for (auto i{0U}; i < len; ++i) {
            for (auto j{0U}; j < len; ++j) {
                if (!visited[i][j] && isIsland(i, j)) {
                    if (first) {
                        first = false;
                        bfs(i, j);
                    }
                    else {
                        std::deque<std::pair<int, int>> queue{};
                        queue.emplace_back(i, j);
                        auto res{0};

                        while (!queue.empty()) {
                            auto queueSize{queue.size()};
                            for (auto k{0U}; k < queueSize; ++k) {
                                auto [row, col] = queue.front();
                                queue.pop_front();

                                for (const auto& move : moves) {
                                    auto nextRow{row + move[0]};
                                    auto nextCol{col + move[1]};
                                    if (isValid(nextRow, nextCol) && visited[nextRow][nextCol]) {
                                        break;
                                    }

                                    if (isWater(nextRow, nextCol)) {
                                        visited[nextRow][nextCol] = 1;
                                        queue.emplace_back(nextRow, nextCol);
                                    }
                                }
                            }
                            ++res;
                        }

                        minRes = std::min(minRes, res);
                        if (minRes == 1) {
                            return minRes;
                        }
                    }
                }
            }
        }

        return minRes;
    }

    const grid_t* grid{nullptr};
    grid_t visited{};
    size_t len{0};
};

TEST(SolutionTest, Test)
{
    EXPECT_EQ(Solution().shortestBridge({{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}), 2);
}
