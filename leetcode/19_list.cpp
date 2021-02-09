#include "header.h"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode preHead;
    preHead.next = head;

    auto first = head;
    auto last = first;
    while (n-- > 0) {
      last = last->next;
    }

    auto pre = &preHead;
    while (last != nullptr) {
      pre = pre->next;
      first = first->next;
      last = last->next;
    }

    pre->next = last;

    return preHead.next;
  }
};
