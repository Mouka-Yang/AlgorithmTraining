#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace testing;

class Solution {
 public:
  using ArrayType = std::vector<int>;

  double findMedianSortedArrays(const ArrayType& nums1,
                                const ArrayType& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    auto sizeX{nums1.size()};
    auto sizeY{nums2.size()};
    auto left{0U};
    auto right{sizeX};
    auto halfSize = (sizeX + sizeY + 1) / 2;

    while (left <= right) {
      auto partitionX = (left + right) / 2;
      auto partitionY = halfSize - partitionX;

      if (partitionX < sizeX && nums1[partitionX] < nums2[partitionY - 1]) {
        left = partitionX + 1;
      } else if (partitionX > 0 && nums1[partitionX - 1] > nums2[partitionY]) {
        right = partitionX - 1;
      } else {
        auto maxLeft{0};
        if (partitionX == 0) {
          maxLeft = nums2[partitionY - 1];
        } else if (partitionY == 0) {
          maxLeft = nums1[partitionX - 1];
        } else {
          maxLeft = std::max(nums1[partitionX - 1], nums2[partitionY - 1]);
        }

        if ((sizeX + sizeY) % 2 != 0) {
          return maxLeft;
        }

        auto minRight{0};
        if (partitionX == sizeX) {
          minRight = nums2[partitionY];
        } else if (partitionY == sizeY) {
          minRight = nums1[partitionX];
        } else {
          minRight = std::min(nums1[partitionX], nums2[partitionY]);
        }

        return (static_cast<double>(minRight) + maxLeft) / 2;
      }
    }

    return 0;
  }
};

TEST(A, A) {
  EXPECT_EQ(Solution().findMedianSortedArrays({1, 3}, {2}), 2.0);
  EXPECT_EQ(Solution().findMedianSortedArrays({1, 2}, {3, 4}), 2.5);
}
