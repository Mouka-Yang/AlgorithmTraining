/*
 Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
Accepted
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int right = 0, left = 0;
        int max_n = nums[0], min_n = nums[n - 1];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < max_n) {
                right = i;
            }
            max_n = max(max_n, nums[i]);
        }
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > min_n) {
                left = j;
            }
            min_n = min(min_n, nums[j]);
        }
        if (right == left)
            return 0;
        return (right - left + 1);
    }
};

int main() {
    vector<int> n{2, 3, 3, 2, 4};
    Solution().findUnsortedSubarray(n);
}