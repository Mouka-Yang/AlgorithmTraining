/*
Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int ss, vector<int> &nums)
    {
        int len = nums.size();
        if (!len)   return 0 ;

        int s = 0, e = 0, total = 0, minLen = INT_MAX;
        while ( e < len )
        {
            total += nums[e++];
            if (total >= ss)
            {
                while ( total >= ss)
                    total -= nums[s++];
                minLen = min(minLen, e - s + 1);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};