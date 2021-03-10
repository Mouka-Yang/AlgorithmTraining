#include "header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        auto* fast = head;
        auto* slow = head;
        ListNode* next = slow->next;

        while ((fast->next != nullptr) && (fast->next->next != nullptr)) {
            fast = fast->next->next;

            auto* tmp = next->next;
            next->next = slow;
            slow = next;
            next = tmp;
        }

        while (next != nullptr) {
            if (next->val != slow->val) {
                return false;
            }
            next = next->next;
            slow = slow->next;
        }

        return true;
    }
};