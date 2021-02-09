#include <algorithm>
#include <array>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int firstMissingPositive(const std::vector<int>& nums) {
    std::unordered_set<int> s{};
    for (auto n : nums) {
      if (n > 0) {
        s.insert(n);
      }
    }

    auto len = s.size();
    auto miss = 1;
    for (auto i = 1; i <= len; ++i) {
      if (s.count(i) == 0) {
        return miss;
      }

      ++miss;
    }

    return miss;
  }

  int firstMissingPositive_Array(const std::vector<int>& nums) {
    std::array<bool, 301> s{false};
    auto len = 0;
    for (auto n : nums) {
      if (n > 0 && n <= 300 && !s[n]) {
        s[n] = true;
        ++len;
      }
    }

    auto miss = 1;
    for (auto i = 1; i <= len; ++i) {
      if (!s[i]) {
        return miss;
      }

      ++miss;
    }

    return miss;
  }
};
