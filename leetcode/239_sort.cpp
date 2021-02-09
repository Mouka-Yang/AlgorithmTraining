#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> res{};
    std::vector<int> heap(nums.begin(), nums.begin() + k);
    std::make_heap(heap.begin(), heap.end());

    res.push_back(heap.front());

    for (auto left = 1, right = k; right < nums.size(); ++left, ++right) {
      if (nums[left - 1] != heap.front()) {
        heap.erase(std::find(heap.begin(), heap.end(), nums[left - 1]));
        heap.push_back(nums[right]);
        std::make_heap(heap.begin(), heap.end());

      } else {
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();

        heap.push_back(nums[right]);
        std::push_heap(heap.begin(), heap.end());
      }
      res.push_back(heap.front());
    }

    return res;
  }
};