#include "header.h"

class Solution {
 public:
  std::pair<int, int> getDifferent(const std::vector<int>& nums, int left,
                                   int right) {
    if (left == right) {
      return {-1, nums[left]};
    }

    if (left == right - 1) {
      return {nums[left], nums[right]};
    }

    auto middle = (left + right) / 2 + 1;

    auto [left_i, left_j] = getDifferent(nums, left, middle - 1);
    auto [right_i, right_j] = getDifferent(nums, middle, right);

    if (left_j == right_j || left_i == right_j) {
      return {left_i, right_j};
    }

    if (left_i == left_j) {
      return {right_i, right_j};
    }

    return {left_i, left_j};
  }

  int singleNonDuplicate(std::vector<int>& nums) {
    auto len = nums.size();

    auto [i, j] = getDifferent(nums, 0, len - 1);
    return i == -1 ? j : i;
  }
};