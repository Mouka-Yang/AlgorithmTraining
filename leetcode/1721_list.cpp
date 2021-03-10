#include "header.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode preHead{};
        preHead.next = head;

        auto* pre = &preHead;
        auto* curr = head;
        auto count = 1;
        while (count++ < k) {
            pre = pre->next;
            curr = curr->next;
        }

        auto* preLeft = pre;
        auto* left = curr;

        auto* right = head;
        pre = &preHead;

        while (curr->next != nullptr) {
            curr = curr->next;
            right = right->next;
            pre = pre->next;
        }

        if (left->next == right) {
            preLeft->next = right;
            left->next = right->next;
            right->next = left;
        }
        else if (right->next == left) {
            pre->next = left;
            right->next = left->next;
            left->next = right;
        }
        else if (right != left) {
            auto* afterRight = right->next;
            preLeft->next = right;
            right->next = left->next;

            pre->next = left;
            left->next = afterRight;
        }

        return preHead.next;
    }
};