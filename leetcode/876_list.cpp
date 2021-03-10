#include "header.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        auto* fast = head;
        auto* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return fast->next == nullptr ? slow : slow->next;
    }
};