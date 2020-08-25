#include "header.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr)
            return head;

        auto tmp = head->next->next;
        auto newHead = head->next;
        newHead->next = head;
        auto preNode = head;
        while (tmp != nullptr) {
            auto leftNode = tmp;
            auto rightNode = tmp->next;
            preNode->next = rightNode;

            tmp = rightNode->next;
            rightNode->next = leftNode;
            preNode = leftNode;
        }
        return newHead;
    }
};

int main()
{
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    Solution().swapPairs(head);
}