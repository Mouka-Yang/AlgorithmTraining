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
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        auto* curr = head;
        auto len = 1;
        while (curr->next != nullptr) {
            curr = curr->next;
            ++len;
        }

        auto* tail = curr;
        auto count = 2;

        curr = head->next;
        auto* tailCurr = tail;
        auto* pre = head;
        while (count < len) {
            if (count % 2 != 0) {
                curr = curr->next;
                pre = pre->next;
            }
            else {
                pre->next = curr->next;
                curr->next = nullptr;
                tailCurr->next = curr;

                curr = pre->next;
                tailCurr = tailCurr->next;
            }
            ++count;
        }

        return head;
    }
};