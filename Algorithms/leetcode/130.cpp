#include "header.h"

using BoardType = std::vector<std::vector<char>>;
class Solution {
public:
    void solve(std::vector<std::vector<char>>& board)
    {
        if (board.empty()) {
            return;
        }
        record_ = BoardType(board);
        board_  = &board;
        rowLen  = board.size();
        colLen  = board.begin()->size();
        findAllOuterO();
        convertInnerO();
    }
    void convertInnerO()
    {
        const auto boardSize = board_->size();
        for (auto i = 0; i < rowLen; i++) {
            for (auto j = 0; j < colLen; j++) {
                if (record_[i][j] != 'Q') {
                    (*board_)[i][j] = 'X';
                }
            }
        }
    }
    void findAllOuterO()
    {
        for (auto i = 0; i < colLen; i++) {
            findAdjacentOuterO(0, i);
            findAdjacentOuterO(rowLen - 1, i);
        }

        for (auto i = 1; i < rowLen - 1; i++) {
            findAdjacentOuterO(i, 0);
            findAdjacentOuterO(i, colLen - 1);
        }
    }
    void findAdjacentOuterO(int x, int y)
    {
        if (!isValidPosition(x, y) || !isOELement(x, y) || record_[x][y] == 'Q') {
            return;
        }

        record_[x][y] = 'Q';
        findAdjacentOuterO(x - 1, y);
        findAdjacentOuterO(x, y - 1);
        findAdjacentOuterO(x + 1, y);
        findAdjacentOuterO(x, y + 1);
    }

    auto isValidPosition(int x, int y) -> bool
    {
        return 0 <= x && x < rowLen && 0 <= y && y < colLen;
    }
    auto isOELement(int x, int y) -> bool
    {
        return (*board_)[x][y] == 'O';
    }

private:
    BoardType* board_{};
    BoardType  record_{};
    size_t     rowLen = 0;
    size_t     colLen = 0;
};

auto main() -> int
{
    BoardType board{{'O', 'O'}, {'O', 'O'}};
    // BoardType board{{'X', 'X', 'X'}, {'O', 'O', 'X'}, {'X', 'X', 'X'}};
    Solution().solve(board);
}