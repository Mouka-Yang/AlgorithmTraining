#include "header.h"

class Solution {
public:
    using Board_T        = std::vector<std::vector<char>>;
    using NumSet         = std::unordered_set<char>;
    const int BOARD_SIZE = 9;

    bool isValidSudoku(Board_T& board)
    {
        return validateColumns(board) && validateRows(board) && validateSquares(board);
    }

    bool validateRows(Board_T& board)
    {
        auto valid = true;
        for (auto i = 0; i < BOARD_SIZE && valid; i++) {
            valid = isValidRow(board, i);
        }
        return valid;
    }

    bool validateColumns(Board_T& board)
    {
        auto valid = true;
        for (auto i = 0; i < BOARD_SIZE && valid; i++) {
            valid = isValidColumn(board, i);
        }
        return valid;
    }

    bool validateSquares(Board_T& board)
    {
        auto valid = true;
        for (auto i = 0; i < BOARD_SIZE && valid; i++) {
            valid = isValidSquare(board, i);
        }
        return valid;
    }
    bool isValidColumn(Board_T& board, int columnNum)
    {
        auto   valid = true;
        NumSet nums{};
        for (int i = 0; i < BOARD_SIZE && valid; i++) {
            if (board[i][columnNum] != '.') {
                auto [_, isSuccess] = nums.emplace(board[i][columnNum]);
                valid               = isSuccess;
            }
        }

        return valid;
    }

    bool isValidRow(Board_T& board, int rowNum)
    {
        auto&  targetRow = board[rowNum];
        auto   valid     = true;
        NumSet nums{};
        for (int i = 0; i < BOARD_SIZE && valid; i++) {
            if (targetRow[i] != '.') {
                auto [_, isSuccess] = nums.emplace(targetRow[i]);
                valid               = isSuccess;
            }
        }
        return valid;
    }

    auto getSquareStartPosition(int squareNum)
    {
        auto startX = (squareNum % 3) * 3;
        auto startY = (squareNum / 3) * 3;
        return std::make_pair(startX, startY);
    }

    bool isValidSquare(Board_T& board, int squareNum)
    {
        auto [x, y]  = getSquareStartPosition(squareNum);
        auto   valid = true;
        NumSet nums{};
        for (int i = 0; i < 3 && valid; i++) {
            for (int j = 0; j < 3 && valid; j++) {
                if (board[x + i][y + j] != '.') {
                    auto [_, isSuccess] = nums.emplace(board[x + i][y + j]);
                    valid               = isSuccess;
                }
            }
        }
        return valid;
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    };

    Solution().isValidSudoku(board);
}