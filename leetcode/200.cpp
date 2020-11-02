#include "gtest/gtest.h"
#include <cstddef>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>

class Solution {
public:
    void init(size_t size)
    {
        ranks.resize(size);
        parents.resize(size);
        std::iota(parents.begin(), parents.begin()+size, 0);
    }

    int findNode(int node)
    {
        if (parents[node] != node && parents[node] != -1) {
            parents[node] = findNode(parents[node]);
        }
        return parents[node];
    }

    void unionNode(size_t nodeX, size_t nodeY)
    {
        auto parentX = findNode(nodeX);
        auto parentY = findNode(nodeY);
        if (ranks[parentX] <= ranks[parentY]) {
            parents[parentX] = parentY;
            if (ranks[parentX] == ranks[parentY]) {
                ++ranks[parentY];
            }
        }
        else {
            parents[parentY] = parentX;
        }
    }

    void unionNode(size_t rowX, size_t colX, size_t rowY, size_t colY)
    {
        unionNode(rowX * colSize + colX, rowY * colSize + colY);
    }

    bool isValidLand(const std::vector<std::vector<char>>& grid, size_t row, size_t col){
        return grid[row][col] == '1';
    }

    void unionSurroundings(const std::vector<std::vector<char>>& grid, size_t row, size_t col)
    {
        if (col < colSize - 1 && isValidLand(grid, row, col + 1)) {
            unionNode(row, col, row, col + 1);
        }
        if (col > 0 && isValidLand(grid, row, col -1)) {
            unionNode(row, col, row, col - 1);
        }
        if (row < rowSize - 1 && isValidLand(grid, row+1, col)) {
            unionNode(row, col, row + 1, col);
        }
        if (row > 0 && isValidLand(grid, row-1, col)) {
            unionNode(row, col, row - 1, col);
        }
    }

    size_t getIslandsNum()
    {
        auto count{0U};
        for (auto i{0}; i < rowSize * colSize; ++i) {
            if (findNode(i) == i) {
                ++count;
            }
        }

        return count;
    }

    int numIslands(const std::vector<std::vector<char>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        init(rowSize * colSize);

        for (auto rowNum{0U}; rowNum < rowSize; ++rowNum) {
            for (auto colNum{0U}; colNum < colSize; ++colNum) {
                if (grid[rowNum][colNum] == '1') {
                    unionSurroundings(grid, rowNum, colNum);
                } else {
                    parents[rowNum *colSize + colNum] = -1;
                }
            }
        }

        return getIslandsNum();
    }

private:
    std::vector<int> parents;
    std::vector<int> ranks;
    size_t rowSize{0};
    size_t colSize{0};
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
