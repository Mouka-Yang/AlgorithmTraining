/*
 Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default
code definition to get new method signature.

Accepted
337,680
Submissions
952,090
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (!len) return intervals;

        sort(intervals.begin(), intervals.end(),
             [](const auto& x, const auto& y) { return x[0] < y[0]; });

        vector<int>& cur = intervals[0];
        vector<vector<int>> res;
        for (const auto& v : intervals) {
            if (cur[1] < v[0]) {
                res.push_back(cur);
                cur = v;
            } else {
                cur[1] = max(cur[1], v[1]);
            }
        }
        res.push_back(cur);
        return res;
    }
};

int main() {
    // vector<vector<int>> n{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> n{{1, 4}, {0, 0}};
    Solution().merge(n);
}