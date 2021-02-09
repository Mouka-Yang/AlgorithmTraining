#include "header.h"

class Solution {
 public:
  ListNode* detectCycle(ListNode* const head) {
    if (!head || !head->next || !head->next->next) {
      return nullptr;
    }

    auto fast = head->next->next;
    auto slow = head->next;

    while (fast != slow && fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }

    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};