/*
3Sum

Share
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)	return { {} };
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;

		for (auto i = 0; i < nums.size() - 2; i++) {
			auto j = i + 1;
			auto k = nums.size() - 1;
			auto rem = 0 - nums[i];
			while (j < k) {
				if (nums[j] + nums[k] > rem)	k--;
				else if (nums[j] + nums[k] < rem)	j++;
				else {
					res.push_back({ nums[i],nums[j++],nums[k--] });
					while (nums[j - 1] == nums[j] && j < k)	j++; 
					while (nums[k + 1] == nums[k] && j < k)	k--; 
				/*	for (auto& res1 : res) {
						for_each(res1.begin(), res1.end(), [](const int& e) {cout << e << " "; });
						cout << endl;
					}*/
				}
			}
			while (nums[i + 1] == nums[i] && i < nums.size()-2) i++;
		}
		return res;
	}
};

int main() {
	//vector<int> test = { -1, 0, 1, 2, -1, -4 };
	vector<int> test = { -6, -8, -9, 4, -14, 6, -10, 7, 12, 13, 4, 9, 7, 14, -12, 7, 0, 14, -1, -3, 2, 2, -3, 11, -6, -10, -13, -13, 1, -9, 2, 2, -2, 8, -9, 0, -9, -12, 14, 10, 8, 3, 4, 0, -6, 7, 14, 9, 6, -2, 13, -15, 8, -5, 3, -13, -8, 5, -11, 0, 11, 6, -13, -14, -9, -15, -7, -11, 10, -7, 14, 4, 3, 3, 11, 13, -13, 11, -1, 0, -6, -10, 0, 9, 0, 10, 11, 0, 0, -14, -15, -12, -1, 10, 12, -2, 2, -10, 2, -2, -10, 2, -13, 1, 12, 5, -1, -15, 1, 5, -8, 3, 10, 8 };
	for (auto& res : Solution().threeSum(test)) {
		for_each(res.begin(), res.end(), [](const int& e) {cout << e << " "; });
		cout << endl;
	}
}