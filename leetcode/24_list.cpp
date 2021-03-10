#include "header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode preHead{};
        preHead.next = head;

        auto* pre = &preHead;
        auto* x = head;
        auto* y = head->next;

        while (x != nullptr && y != nullptr) {
            pre->next = y;
            x->next = y->next;
            y->next = x;
            pre = x;

            x = x->next;
            if (x != nullptr) {
                y = x->next;
            }
        }

        return preHead.next;
    }
};