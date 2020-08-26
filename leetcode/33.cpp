/*
Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;

        int s = 0, e = len - 1, idx = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                idx = m;
                break;
            } else if (nums[e] > nums[m] && target > nums[m] && target <= nums[e] ||
                        nums[e] < nums[m] && (nums[e] >= target || nums[m] < target)) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return idx;
    }
};

int main() {
    vector<int> n{8,9,2,3,4};
    Solution().search(n, 9);
}