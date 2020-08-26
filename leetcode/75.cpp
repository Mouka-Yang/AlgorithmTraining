/*
Sort Colors

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;

        int s0 = 0, s1 = 0, s2 = len - 1;
        while (s1 < s2) {
            if (nums[s1] == 0) {
                swap(nums[s1++], nums[s0++]);
            } else if (nums[s1] == 2) {
                swap(nums[s1], nums[s2--]);
            } else {
                s1++;
            }
        }
    }
};