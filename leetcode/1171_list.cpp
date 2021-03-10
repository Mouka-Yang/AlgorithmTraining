#include "header.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode preHead{};
        preHead.next = head;

        std::map<int, ListNode*> m{};
        m.emplace(0, &preHead);

        auto* curr = head;
        auto prefix = 0;
        while (curr != nullptr) {
            prefix += curr->val;
            if (m.count(prefix) == 0) {
                m.emplace(prefix, curr);
                curr = curr->next;
            }
            else {
                auto* pre = m[prefix];
                auto* start = pre->next;
                auto sum = prefix + start->val;
                while (sum != prefix) {
                    m.erase(sum);
                    start = start->next;
                    sum += start->val;
                }
                pre->next = start->next;
                start->next = nullptr;

                curr = pre->next;
            }
        }

        return preHead.next;
    }
};