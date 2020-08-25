/*
Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements
appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the
returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                int j = nums[i]-1;
                while (j + 1 != nums[j]) {
                    int tmp = nums[j]-1;
                    nums[j] = j+1;
                    j = tmp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> n{4, 3, 2, 7, 8, 2, 3, 1};
    Solution().findDisappearedNumbers(n);
}