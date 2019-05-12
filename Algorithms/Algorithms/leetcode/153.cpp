/*
Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];

        int s = 0, e = len - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] < nums[(len + m - 1) % len] && nums[m] < nums[(m + 1) % len]) {
                return nums[m];
            } else if (nums[e] > nums[m]) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> n{4, 5, 6, 7, 0, 1, 2};
    Solution().findMin(n);
}