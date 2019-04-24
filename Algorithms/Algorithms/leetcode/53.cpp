/*
Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        auto len = nums.size();
        auto maxSum = 0;
        // vector<int> dp(len + 1, 0);
        // for (int i = 1; i <= len; i++) {
        //     maxSum = max(maxSum, nums[i - 1] + dp[i - 1]);
        //     dp[i] = nums[i-1] + dp[i - 1] < 0 ? 0 : nums[i-1] + dp[i - 1];
        // }
        int dp = 0;
        for (int i = 1; i < len; i++) {
            maxSum = max(maxSum, nums[i - 1] + dp);
            dp = nums[i - 1] + dp < 0 ? 0 : nums[i - 1] + dp;
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(nums) << "\n";
}