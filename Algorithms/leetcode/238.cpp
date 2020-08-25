/*
 Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        partial_sum(nums.begin(), nums.end(), res.begin(), multiplies<int>());

        int rProduct = 1;
        for (int i = len-1; i >=1; i--){
            res[i] = rProduct * res[i - 1];
            rProduct *= nums[i];
        }
        res[0] = rProduct;
        return res;
    }
};