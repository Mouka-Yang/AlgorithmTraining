#include <algorithm>
#include <vector>

class Solution {
 public:
  int trap_dp(const std::vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    auto len = height.size();
    std::vector<int> left(len, 0);
    std::vector<int> right(len, 0);

    left[0] = height[0];
    right[len - 1] = height[len - 1];

    for (auto i = 1; i < len; ++i) {
      left[i] = std::max(left[i - 1], height[i]);
    }

    for (int j = len - 2; j >= 0; --j) {
      right[j] = std::max(right[j + 1], height[j]);
    }

    auto sum = 0;
    for (auto i = 0; i < len; ++i) {
      sum += std::min(left[i], right[i]) - height[i];
    }

    return sum;
  }

  int trap_broute_force(const std::vector<int>& height) {
    auto len = height.size();
    auto sum = 0;

    for (auto i = 0; i < len; ++i) {
      auto leftMax = 0;
      auto rightMax = 0;

      for (auto j = i; j >= 0; --j) {
        leftMax = std::max(leftMax, height[j]);
      }

      for (auto k = i; k < len; ++k) {
        rightMax = std::max(rightMax, height[k]);
      }

      sum += std::min(leftMax, rightMax) - height[i];
    }

    return sum;
  }

  int trap_stack(const std::vector<int>& height) {
    std::vector<int> s{};
    auto sum = 0;
    auto len = height.size();

    for (auto i = 0; i < len; i++) {
      while (!s.empty() && height[i] > height[s.back()]) {
        auto top = s.back();
        s.pop_back();

        if (s.empty()) {
          break;
        }

        auto currWidth = i - s.back() - 1;
        auto currHeight = std::min(height[s.back()], height[i]) - height[top];
        sum += currHeight * currWidth;
      }

      s.push_back(i);
    }

    return sum;
  }
};
