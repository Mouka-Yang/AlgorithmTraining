/*
Game of Life

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        auto isValid = [m, n](int x, int y) {
            if (x >= 0 && x < m && y >= 0 && y < n)
                return true;
            return false;
        };
        enum { Dead = 0,
               Live,
               ToLive,
               ToDie };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                for (int ni = i - 1; ni <= i + 1; ni++) {
                    for (int nj = j - 1; nj <= j + 1; nj++) {
                        if (isValid(ni, nj) && (board[ni][nj] == Live || board[ni][nj] == ToDie)) {
                            liveNeighbors++;
                        }
                    }
                }
                if (board[i][j] == Live || board[i][j] == ToDie) liveNeighbors--;

                if (board[i][j] == Live && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = ToDie;
                } else if (board[i][j] == Dead && liveNeighbors == 3) {
                    board[i][j] = ToLive;
                }
            }
        }

        for (auto& row : board) {
            for (auto& x : row) {
                if (x == ToLive) {
                    x = Live;
                } else if (x == ToDie) {
                    x = Dead;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> n{
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    Solution().gameOfLife(n);
}