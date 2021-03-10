#include "header.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode preHead{};
        preHead.next = head;

        auto* curr = head;
        auto* pre = &preHead;

        while (curr != nullptr) {
            if (curr->val == val) {
                pre->next = curr->next;
            }
            else {
                pre = curr;
            }
            curr = curr->next;
        }

        return preHead.next;
    }
};