#include "header.h"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        auto* currA = headA;
        auto* currB = headB;

        while (true) {
            if (currA == currB) {
                return currA;
            }

            if (currA == nullptr) {
                currA = headB;
            }
            else {
                currA = currA->next;
            }

            if (currB == nullptr) {
                currB = headA;
            }
            else {
                currB = currB->next;
            }
        }
    }
};