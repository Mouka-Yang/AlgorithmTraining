#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode preHead{};
    preHead.next = head;

    auto start = head;
    auto pre = &preHead;
    while (start != nullptr) {
      auto tmpStart = start;
      start = reversePartialList(pre, start, k);
      pre = tmpStart;
    }

    return preHead.next;
  }

  bool isLengthShorterThanK(ListNode* head, int k) {
    auto curr = head;
    auto count = 0;

    while (curr != nullptr && count++ < k) {
      curr = curr->next;
    }

    return count < k;
  }

  ListNode* reversePartialList(ListNode* pre, ListNode* start, int len) {
    if (start == nullptr || isLengthShorterThanK(start, len)) {
      return nullptr;
    }

    auto curr = start;
    ListNode* tmpPre = nullptr;
    ListNode* tmpNext = nullptr;
    while (len-- > 0) {
      tmpNext = curr->next;
      curr->next = tmpPre;

      tmpPre = curr;
      curr = tmpNext;
    }
    pre->next = tmpPre;
    start->next = curr;

    return curr;
  }
};

TEST(A, A) {
  auto list1 = ConstructList({1, 2, 3, 4, 5, 6});
  Solution().reversePartialList(list1, list1->next, 2);
}

TEST(B, B) {
  auto l1 = ConstructList({1, 2, 3, 4, 5});
  l1 = Solution().reverseKGroup(l1, 2);
  PrintList(l1);

  auto l2 = ConstructList({1, 2, 3, 4, 5});
  l2 = Solution().reverseKGroup(l2, 3);
  PrintList(l2);

  l2 = Solution().reverseKGroup(l2, 1);
  PrintList(l2);
}
