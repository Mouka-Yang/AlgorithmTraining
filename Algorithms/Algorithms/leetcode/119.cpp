/*
Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);

        for (int j = 0; j <= rowIndex; j++) {
            res[0] = 1;
            if (j > 1)
                for (int i = j-1; i >= 1; i--) 
                    res[i] = res[i - 1] + res[i];
            res[j] = 1;
        }
        return res;
    }
};

int main(){
    auto res = Solution().getRow(3);
    for_each(res.begin(), res.end(), [](const int x) {
        cout << x << ' ';
    });
    cout << "\n";
}