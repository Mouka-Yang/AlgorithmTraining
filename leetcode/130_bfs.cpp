#include "gtest/gtest.h"

#include <algorithm>
#include <array>
#include <deque>
#include <string>
#include <vector>
using namespace testing;
constexpr std::array<std::array<char, 2>, 4> moves = {{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};

class Solution {
public:
    bool isValid(int row, int col, const std::vector<std::vector<char>>& board)
    {
        return row >= 0 && col >= 0 && row < rowSize && col < colSize && board[row][col] == 'O';
    }

    bool isVisited(int row, int col)
    {
        return visited[row][col] == 1;
    }

    void visit(size_t row, size_t col)
    {
        visited[row][col] = 1;
    }

    bool isOnBoarder(size_t row, size_t col)
    {
        return row == 0 || row == rowSize - 1 || col == 0 || col == colSize - 1;
    }

    void dfs(size_t i, size_t j, const std::vector<std::vector<char>>& board)
    {
        std::vector<std::pair<size_t, size_t>> res{};
        std::deque<std::pair<size_t, size_t>> queue{};
        queue.emplace_back(i, j);
        res.emplace_back(i, j);

        auto onBoard{false};
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop_front();

            if (isOnBoarder(row, col)) {
                onBoard = true;
            }

            for (auto [moveRow, moveCol] : moves) {
                auto nextRow{row + moveRow};
                auto nextCol{col + moveCol};
                if (isValid(nextRow, nextCol, board) && !isVisited(nextRow, nextCol)) {
                    visit(nextRow, nextCol);
                    queue.emplace_back(nextRow, nextCol);
                    res.emplace_back(nextRow, nextCol);
                }
            }
        }

        if (!onBoard) {
            std::move(res.begin(), res.end(), std::back_inserter(startNodes));
        }
    }

    void solve(std::vector<std::vector<char>>& board)
    {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        }

        rowSize = board.size();
        colSize = board[0].size();
        visited = std::vector<std::vector<int>>(rowSize, std::vector<int>(colSize, 0));

        // no need to traverse boarder node, so just start at 1 and end at size-1
        for (auto i{1U}; i < rowSize - 1; ++i) {
            for (auto j{1U}; j < colSize - 1; ++j) {
                if (isValid(i, j, board) && !isVisited(i, j)) {
                    visit(i, j);
                    dfs(i, j, board);
                }
            }
        }

        for (auto [i, j] : startNodes) {
            board[i][j] = 'X';
        }
    }

private:
    size_t rowSize{};
    size_t colSize{};
    std::vector<std::vector<int>> visited{};
    std::vector<std::pair<size_t, size_t>> startNodes{};
};

TEST(SolutionTest, Test)
{
    auto board = std::vector<std::vector<char>>{
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    Solution().solve(board);

    EXPECT_EQ(
        board, std::vector<std::vector<char>>(
                   {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}}));
}

TEST(SolutionTest2, Test)
{
    auto board = std::vector<std::vector<char>>{
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}};

    auto res = std::vector<std::vector<char>>{
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}};

    Solution().solve(board);

    EXPECT_EQ(board, res);
}
