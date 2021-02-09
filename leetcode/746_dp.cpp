#include <algorithm>
#include <vector>

class Solution {
 public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    if (cost.size() == 2) {
      return 0;
    }

    auto pre_pre = 0;
    auto pre = 0;
    auto sum = 0;
    for (auto i = 3; i <= cost.size() + 1; ++i) {
      sum = std::min(pre + cost[i - 2], pre_pre + cost[i - 3]);
      pre_pre = pre;
      pre = sum;
    }

    return sum;
  }
};