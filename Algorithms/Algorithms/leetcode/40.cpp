/*
 Combination Sum II

Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    void findSubSum(vector<int>& candidates, int start, vector<int>& subres,
                    vector<vector<int>>& res, int subsum) {
        if (subsum == 0) {
            res.push_back(subres);
            return;
        }

        if (subsum < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            subres.push_back(candidates[i]);
            findSubSum(candidates, i+1, subres, res, subsum - candidates[i]);
            subres.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subres;
        vector<vector<int>> res;
        findSubSum(candidates, 0, subres, res, target);
        return res;
    }
};