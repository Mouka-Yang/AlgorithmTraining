#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    ListNode* reverseListIteration(ListNode* head)
    {
        ListNode preHead{};
        preHead.next = head;

        auto* curr = head;
        ListNode* pre = nullptr;

        while (curr != nullptr) {
            auto* next = curr->next;
            curr->next = pre;

            pre = curr;
            curr = next;
        }

        return pre;
    }

    ListNode* reverseList(ListNode* head)
    {
        std::vector<ListNode*> nodeArray{};

        auto curr = head;
        while (curr != nullptr) {
            nodeArray.push_back(curr);
            curr = curr->next;
        }

        ListNode preHead{};
        auto pre = &preHead;
        std::for_each(std::crbegin(nodeArray), std::crend(nodeArray), [&pre](const auto& node) {
            pre->next = node;
            pre = node;
        });

        pre->next = nullptr;
        return preHead.next;
    }

    ListNode* innerTraverse(ListNode* node, ListNode* preHead)
    {
        if (node == nullptr) {
            return preHead;
        }

        auto pre = innerTraverse(node->next, preHead);
        pre->next = node;

        return node;
    }

    ListNode* reverseListRecurse(ListNode* head)
    {
        ListNode preHead{};

        auto res = innerTraverse(head, &preHead);
        res->next = nullptr;

        return preHead.next;
    }
};

TEST(A, A)
{
    auto head = ConstructList({1, 2, 3, 4, 5});
    Solution().reverseList(head);
}
