#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

namespace MyAlgorithm {

template <typename T>
using ArrayType = std::vector<T>;

using IntegerArray = ArrayType<size_t>;
using ValueType = size_t;

size_t partition(IntegerArray& array, size_t left, size_t right,
                 size_t pivotIndex) {
  auto pivotValue{array[pivotIndex]};
  auto storeIndex{left};

  std::swap(array[right], array[pivotIndex]);

  for (auto i{left}; i < right; ++i) {
    if (array[i] < pivotValue) {
      std::swap(array[i], array[storeIndex++]);
    }
  }
  std::swap(array[storeIndex], array[right]);

  return storeIndex;
}

ValueType QuickSelect(IntegerArray& array, size_t left, size_t right,
                      size_t k) {
  assert(left <= right);

  while (left <= right) {
    if (left == right) {
      return array[left];
    }

    auto pivotIndex = (left + right) / 2;
    auto storeIndex = partition(array, left, right, pivotIndex);

    if (storeIndex == k) {
      return array[k];
    }

    if (storeIndex < k) {
      left = storeIndex + 1;
    } else {
      right = storeIndex - 1;
    }
  }

  return 0;
}

}  // namespace MyAlgorithm

class Solution {
 public:
  int findKthLargest(std::vector<size_t>& nums, int k) {
    // return MyAlgorithm::QuickSelect(nums, 0, nums.size() - 1, nums.size() -
    // k);
    return methodByHeap2(nums, k);
  }

  int methodByHeap(std::vector<size_t>& nums, int k) {
    std::vector<size_t> heap{nums[0]};
    for (auto i = 1; i < nums.size(); ++i) {
      heap.push_back(nums[i]);
      std::push_heap(heap.begin(), heap.end());

      if (heap.size() > nums.size() - k + 1) {
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();
      }
    }

    return heap.front();
  }

  int methodByHeap2(std::vector<size_t>& nums, int k) {
    auto len = nums.size();
    std::make_heap(nums.begin(), nums.end());

    while (nums.size() > len - k + 1) {
      std::pop_heap(nums.begin(), nums.end());
      nums.pop_back();
    }

    return nums.front();
  }
};

TEST(A, A) {
  std::vector<size_t> a1{3, 2, 1, 5, 6, 4};
  std::vector<size_t> a2{3, 2, 3, 1, 2, 4, 5, 5, 6};
  EXPECT_EQ(Solution().findKthLargest(a1, 2), 5);
  EXPECT_EQ(Solution().findKthLargest(a2, 4), 4);
}
