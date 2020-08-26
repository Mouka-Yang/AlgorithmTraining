/*
3Sum Closest

Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        auto min = INT_MAX;
        auto res = 0;
        for (auto i = 0; i < nums.size() - 2; i++) {
            auto j = i + 1;
            auto k = nums.size() - 1;
            while (j < k) {
                auto total = nums[j] + nums[k] + nums[i];
                auto delta = total - target;
                if (min > abs(delta)) {
                    min = abs(delta);
                    res = total;
                }
                if (delta > 0)
                    k--;
                else if (delta < 0)
                    j++;
                else
                    return target;
            }
        }
        return res;
    }
};
