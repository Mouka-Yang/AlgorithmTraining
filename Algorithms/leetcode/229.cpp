/*
Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, len = nums.size();
        int t1, t2;

        for (auto x : nums) {
            if (t1 == x) {
                c1++;
            } else if (t2 == x) {
                c2++;
            } else if (c1 == 0) {
                t1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                t2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        vector<int> res;
        if (c1 > 0 && count(nums.begin(), nums.end(), t1) > len / 3) res.push_back(t1);
        if (c2 > 0 && count(nums.begin(), nums.end(), t2) > len / 3) res.push_back(t2);

        return res;
    }
};