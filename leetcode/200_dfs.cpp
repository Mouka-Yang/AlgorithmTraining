#include "gtest/gtest.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <vector>

class Solution {
public:
    int toIndex(int row, int col)
    {
        return row * colSize + col;
    }

    void visit(const std::vector<std::vector<char>>& grid, int row, int col)
    {
        if (row < 0 || row >= rowSize || col < 0 || col >= colSize || visited[toIndex(row, col)] == 1 || grid[row][col] == '0') {
            return;
        }

        visited[toIndex(row, col)] = 1;

        visit(grid, row, col + 1);
        visit(grid, row, col - 1);
        visit(grid, row + 1, col);
        visit(grid, row - 1, col);
    }

    int numIslands(const std::vector<std::vector<char>>& grid)
    {
        rowSize = grid.size();
        colSize = grid[0].size();
        visited.resize(rowSize * colSize, 0);
        auto count{0U};

        for (auto rowNum{0U}; rowNum < rowSize; ++rowNum) {
            for (auto colNum{0U}; colNum < colSize; ++colNum) {
                if (grid[rowNum][colNum] != '0' && visited[toIndex(rowNum, colNum)] == 0) {
                    ++count;
                    visit(grid, rowNum, colNum);
                }
            }
        }

        return count;
    }

private:
    std::vector<int> visited{};
    int rowSize{0};
    int colSize{0};
};

TEST(SolutionTest, Test){
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
