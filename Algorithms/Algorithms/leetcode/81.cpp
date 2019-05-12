/*
Search in Rotated Sorted Array II
Medium

630

299

Favorite

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;

        int s = 0, e = len - 1, idx = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                idx = m;
                break;
            }
            while (m < e && nums[m] == nums[e]) e--;

            if (e > m && (nums[e] > nums[m] && target > nums[m] && target <= nums[e] ||
                          nums[e] < nums[m] && (nums[e] >= target || nums[m] < target))) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return idx != -1;
    }
};