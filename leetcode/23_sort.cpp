#include <queue>

#include "header.h"

struct nodeCompare {
  bool operator()(const ListNode* lhs, const ListNode* rhs) {
    return lhs->val < rhs->val;
  }
};

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }

    std::priority_queue<ListNode*, std::vector<ListNode*>, nodeCompare> q{};
    for (auto list : lists) {
      if (list != nullptr) {
        q.push(list);
      }
    }

    ListNode head{};
    ListNode* curr = &head;
    while (!q.empty()) {
      auto currMin = q.top();
      q.pop();

      curr->next = currMin;
      curr = curr->next;

      if (currMin->next != nullptr) {
        q.push(currMin->next);
      }
    }

    return head.next;
  }
};