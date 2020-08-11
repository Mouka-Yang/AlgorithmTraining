#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto [nodeBeforeTheDeleted, isDeleteHead] = getDeletedNodePair(head, n);

        if (isDeleteHead) {
            return DeleteHeadNode(head);
        }
        else {
            DeleteInnerNode(nodeBeforeTheDeleted);
            return head;
        }
    }
    std::tuple<ListNode *, bool> getDeletedNodePair(ListNode *head, int n)
    {
        auto rightPtr = head;
        auto nodeBeforeTheDeleted = head;
        auto moveCount = 0;

        while (rightPtr != nullptr) {
            rightPtr = rightPtr->next;
            nodeBeforeTheDeleted = moveCount > n ? nodeBeforeTheDeleted->next : nodeBeforeTheDeleted;
            moveCount++;
        }

        auto isDeleteHead = moveCount == n;
        return std::make_tuple(nodeBeforeTheDeleted, isDeleteHead);
    }

    void DeleteInnerNode(ListNode *nodeBeforeTheDeleted)
    {
        auto deletedNode = nodeBeforeTheDeleted->next;
        auto nodeAfterTheDeleted = deletedNode->next;
        nodeBeforeTheDeleted->next = nodeAfterTheDeleted;
        deletedNode->next = nullptr;
    }

    ListNode *DeleteHeadNode(ListNode *headNode)
    {
        auto newHead = headNode->next;
        headNode->next = nullptr;
        return newHead;
    }
};

int main()
{
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution().removeNthFromEnd(head, 2);
}