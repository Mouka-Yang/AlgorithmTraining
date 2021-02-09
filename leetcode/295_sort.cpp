#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

#include "gtest/gtest.h"
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum2(int num) {
    if (len % 2 == 0) {
      left_q.push(num);
      right_q.push(left_q.top());

      left_q.pop();
    } else {
      right_q.push(num);
      left_q.push(right_q.top());

      right_q.pop();
    }

    ++len;
  }

  void addNum(int num) {
    if (getSize() % 2 == 0) {
      left_heap.push_back(num);
      std::push_heap(left_heap.begin(), left_heap.end());

      auto leftMax = left_heap.front();
      std::pop_heap(left_heap.begin(), left_heap.end());
      left_heap.pop_back();

      right_heap.push_back(leftMax);
      std::push_heap(right_heap.begin(), right_heap.end(), std::greater());
    } else {
      right_heap.push_back(num);
      std::push_heap(right_heap.begin(), right_heap.end(), std::greater());

      auto rightMin = right_heap.front();
      std::pop_heap(right_heap.begin(), right_heap.end(), std::greater());
      right_heap.pop_back();

      left_heap.push_back(rightMin);
      std::push_heap(left_heap.begin(), left_heap.end());
    }
  }

  double findMedian() {
    if (getSize() % 2 == 0) {
      return (static_cast<double>(left_heap.front()) + right_heap.front()) / 2;
    }

    return right_heap.front();
  }

  size_t getSize() const { return left_heap.size() + right_heap.size(); }

  std::vector<int> left_heap{};
  std::vector<int> right_heap{};

  std::priority_queue<int> left_q{};
  std::priority_queue<int, std::vector<int>, std::greater<int>> right_q{};
  std::size_t len{0};
};

TEST(A, A) {
  MedianFinder f;
  f.addNum(1);
  f.addNum(2);
  EXPECT_EQ(f.findMedian(), 1.5);
  f.addNum(3);
  EXPECT_EQ(f.findMedian(), 2);
}
