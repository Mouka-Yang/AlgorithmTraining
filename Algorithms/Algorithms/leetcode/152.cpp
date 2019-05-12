/*
Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int curMin = nums[0], curMax = nums[0], maxPro = nums[0];

        for (int i = 1; i < len; i++) {
            if (nums[i] < 0) {
                swap(curMin, curMax);
            }

            curMin = min(curMin, curMin * nums[i]);
            curMax = max(curMax, curMax * nums[i]);
            maxPro = max(maxPro, curMax);
        }
        return maxPro;
    }
};

int main() {
    vector<int> n{
        -3, -1, 3, 5, -6, -6, -1, 6, -3, -5, 1, 0, -6, -5, 0, -2, 6, 1, 0, 5};
    Solution().maxProduct(n);
}