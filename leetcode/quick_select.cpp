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
}

}  // namespace MyAlgorithm
