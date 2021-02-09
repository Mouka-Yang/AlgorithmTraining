#include "gtest/gtest.h"
#include "header.h"
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int val_ = 0, Node* next_ = nullptr, Node* random_ = nullptr)
      : val(val_), next(next_), random(random_) {}
};

class Solution {
 public:
  std::unordered_map<Node*, Node*> nodeMap{};

  Node* copyRandomList(Node* head) {
    auto oldCurr = head;
    Node preNewHead{};
    auto preNewCurr = &preNewHead;

    while (!oldCurr) {
      auto currNode = getCopyNode(oldCurr);
      currNode->next = getCopyNode(oldCurr->next);
      currNode->random = getCopyNode(oldCurr->random);

      preNewCurr->next = currNode;
      preNewCurr = currNode;
      oldCurr = oldCurr->next;
    }

    return preNewHead.next;
  }

  Node* getCopyNode(Node* source) {
    Node* target = nullptr;
    if (nodeMap.count(source) != 0) {
      target = nodeMap[source];
    } else if (source != nullptr) {
      target = new Node{source->val};
      nodeMap.emplace(source, target);
    }

    return target;
  }
};

TEST(A, A) {
  Node* a = new Node{1};
  Node* b = new Node{2};
  Node* c = new Node{3};
  a->next = b;
  b->next = c;
  a->random = nullptr;
  b->random = a;
  c->random = a;

  EXPECT_EQ(Solution().copyRandomList(a), nullptr);
}