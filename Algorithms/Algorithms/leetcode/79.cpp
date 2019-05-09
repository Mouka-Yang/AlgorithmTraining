/*
 Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool search(vector<vector<char>>& board, string word, int wordIndex, int x, int y, vector<vector<bool>>& visited) {
        if (!visited[x][y] && board[x][y] == word[wordIndex]) {
            if (wordIndex == word.size() - 1) {
                return true;
            }

            visited[x][y] = true;
            if (x != 0 && search(board, word, wordIndex + 1, x - 1, y, visited) ||
                x != board.size() - 1 && search(board, word, wordIndex + 1, x + 1, y, visited) ||
                y != 0 && search(board, word, wordIndex + 1, x, y - 1, visited) ||
                y != board[0].size() - 1 && search(board, word, wordIndex + 1, x, y + 1, visited)) {
                return true;
            } else {
                visited[x][y] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size()) return false;

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto wordBegin = word.cbegin();
        auto wordEnd = word.cend();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};