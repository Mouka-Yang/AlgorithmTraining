#include "header.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2)
    {
        auto count = 1;
        auto* start = l1->next;
        auto* preStart = l1;

        while (count++ < a) {
            start = start->next;
            preStart = preStart->next;
        }

        auto* end = start;
        while (count++ < b) {
            end = end->next;
        }

        auto* curr = l2;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        preStart->next = l2;
        curr->next = end->next;

        end->next = nullptr;

        return l1;
    }
};