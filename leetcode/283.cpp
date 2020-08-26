/*
Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0 ) {
                swap(nums[i], nums[index++]);
            }
        }
    }
};

int main() {
    vector<int> n{0, 1, 0, 3, 0, 0, 4};
    Solution().moveZeroes(n);
}