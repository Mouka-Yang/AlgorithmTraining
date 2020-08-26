/*
 Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int reverse(int x) {
        auto res = 0;

        while (x) {
            if (INT_MAX / 10 < res || INT_MIN / 10 > res)
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
    cout << Solution().reverse(123) << "\n";
}