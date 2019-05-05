/*
Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target
number (target), find all unique combinations in candidates where the candidate
numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of
times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
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

        for (int i = start; i < candidates.size() ; i++) {
            subres.push_back(candidates[i]);
            findSubSum(candidates, i, subres, res, subsum - candidates[i]);
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

int main() {
    vector<int> n{2, 3, 6, 7};
    Solution().combinationSum(n, 7);
}