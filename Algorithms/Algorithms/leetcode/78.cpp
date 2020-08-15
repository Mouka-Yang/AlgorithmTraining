/*
Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    void subsubsets2(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& partial)
    {
        if (start == nums.size()) {
            res.push_back(partial);
        }

        partial.push_back(nums[start]);
        subsubsets(nums, start + 1, res, partial);
        partial.pop_back();
        subsubsets(nums, start + 1, res, partial);
    }

    void subsubsets(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& partial)
    {
        res.push_back(partial);
        for (auto i = start; i < nums.size(); i++) {
            partial.push_back(nums[i]);
            subsubsets(nums, i + 1, res, partial);
            partial.pop_back();
        }
    }
    vector<vector<int>> subsets2(vector<int>& nums)
    {
        vector<int>         partial;
        vector<vector<int>> res;
        subsubsets(nums, 0, res, partial);

        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res{{}};

        for (int i = 0; i < nums.size(); i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};