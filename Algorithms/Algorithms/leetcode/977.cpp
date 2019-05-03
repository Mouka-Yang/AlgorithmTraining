/*

Squares of a Sorted Array

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        vector<int> res(len);

        for (int i = 0, j = len - 1, k = len-1; i <= j;){
            if (abs(A[i]) > abs(A[j])){
                res[k--] = A[i]*A[i];
                i++;
            }
            else{
                res[k--] = A[j]*A[j];
                j--;
            }
        }
        return res;
    }
};