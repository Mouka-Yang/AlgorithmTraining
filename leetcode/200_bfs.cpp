#include "gtest/gtest.h"

#include <algorithm>
#include <deque>
#include <vector>

class Solution {
public:
    auto getConnectedIslands(size_t row, size_t col, const std::vector<std::vector<char>>& grid)
    {
        std::vector<std::pair<size_t, size_t>> res{};

        if (row > 0 && isIsland(row - 1, col, grid)) {
            res.emplace_back(row - 1, col);
        }

        if (col > 0 && isIsland(row, col - 1, grid)) {
            res.emplace_back(row, col - 1);
        }

        if (row < totalRow - 1 && isIsland(row + 1, col, grid)) {
            res.emplace_back(row + 1, col);
        }

        if (col < totalCol - 1 && isIsland(row, col + 1, grid)) {
            res.emplace_back(row, col + 1);
        }

        return res;
    }

    void visit(size_t currRow, size_t currCol, size_t& count, std::vector<std::vector<char>>& grid)
    {
        ++count;
        std::deque<std::pair<size_t, size_t>> q{};
        q.emplace_back(currRow, currCol);

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop_front();

            auto nextIslands{getConnectedIslands(row, col, grid)};
            for (auto [nextRow, nextCol] : nextIslands) {
                grid[nextRow][nextCol] = '0';
                q.emplace_back(nextRow, nextCol);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        totalRow = grid.size();
        totalCol = grid[0].size();

        size_t count{0};
        for (auto i{0U}; i < totalRow; ++i) {
            for (auto j{0U}; j < totalCol; ++j) {
                if (isIsland(i, j, grid)) {
                    visit(i, j, count, grid);
                }
            }
        }

        return count;
    }

    auto isIsland(size_t row, size_t col, const std::vector<std::vector<char>>& grid) -> bool
    {
        return grid[row][col] == '1';
    }

private:
    size_t totalRow{};
    size_t totalCol{};
};

TEST(SolutionTest, Test)
{
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    EXPECT_EQ(Solution().numIslands(grid), 1);

    std::vector<std::vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    EXPECT_EQ(Solution().numIslands(grid2), 3);
}
