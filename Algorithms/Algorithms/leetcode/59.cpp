/*
Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {{}};

        int loopCount = (n + 1) / 2;

        vector<vector<int>> res(n, vector<int>(n));
        int count = 1;
        for (int loop = 0; loop < loopCount; loop++) {
            for (int i = loop; i < n - loop; i++) {
                res[loop][i] = count++;
            }
            for (int j = loop + 1; j < n - loop; j++) {
                res[j][n - 1 - loop] = count++;
            }
            if (loop < n - 1 - loop) {
                for (int i = n - 2 - loop; i >= loop; i--) {
                    res[n - 1 - loop][i] = count++;
                }
                for (int j = n - 2 - loop; j >= loop + 1; j--) {
                    res[j][loop] = count++;
                }
            }
        }
        return res;
    }
};

int main() { Solution().generateMatrix(4); }