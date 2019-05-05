/*
Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int i = 0, j = len - 1;
        int s = -1, e = -1;

        i = 0;
        j = len - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] == target && (m == 0 || nums[m - 1] != target)) {
                s = m;
                break;
            } else if (nums[m] < target) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }

        if (s == -1) return {-1, -1};

        i = s;
        j = len - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] == target && (m == len - 1 || nums[m + 1] != target)) {
                e = m;
                break;
            } else if (nums[m] > target) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }

        return {s, e};
    }
};

int main() {
    vector<int> n{1};
    Solution().searchRange(n, 1);
}