/*
Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    void subsub(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& partial) {
        res.push_back(partial);
        for (int i = start; i < nums.size(); i++){
            if (i != start && nums[i] != nums[i-1]){
                partial.push_back(nums[i]);
                subsub(nums, i + 1, res, partial);
                partial.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> partial;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        subsub(nums, 0, res, partial);
    }
};