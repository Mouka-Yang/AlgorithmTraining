/*
Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;

        int j = len - 2;
        while (j >= 0 && nums[j] >= nums[j + 1]) j--;

        int i = j + 1;
        while (i < len && nums[j] < nums[i]) i++;
        
        swap(nums[j], nums[i - 1]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};