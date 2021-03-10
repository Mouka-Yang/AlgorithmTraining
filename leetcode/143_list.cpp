#include "header.h"

class Solution {
public:
    ListNode* reverseListIteration(ListNode* head)
    {
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
    void reorderList(ListNode* head)
    {
        auto len = 0;
        auto* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            ++len;
        }

        curr = head;
        auto count = len / 2;
        while (curr != nullptr && count-- > 0) {
            curr = curr->next;
        }

        auto* tail = reverseListIteration(curr);

        auto* currHead = head;
        auto* currTail = tail;
        while (!(currHead->next == currTail || currHead == currTail)) {
            auto* headNext = currHead->next;
            currHead->next = currTail;
            auto* tailNext = currTail->next;
            currTail->next = headNext;

            currHead = headNext;
            currTail = tailNext;
        }
    }
};