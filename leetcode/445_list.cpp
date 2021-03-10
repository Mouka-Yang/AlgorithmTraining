#include "header.h"

class Solution {
public:
    std::pair<ListNode*, int> reverseCopy(ListNode* head)
    {
        auto* curr = head;
        auto len = 0;
        ListNode* copyHead = nullptr;
        while (curr != nullptr) {
            auto* newCurr = new ListNode(curr->val);
            newCurr->next = copyHead;
            copyHead = newCurr;

            curr = curr->next;
            len++;
        }

        return {copyHead, len};
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto [copy1Head, len1] = reverseCopy(l1);
        auto [copy2Head, len2] = reverseCopy(l2);

        auto c = 0;
        auto* longHead = len1 > len2 ? copy1Head : copy2Head;
        auto* shortHead = len1 > len2 ? copy2Head : copy1Head;
        ListNode resultHead{};
        resultHead.next = longHead;
        auto* pre = &resultHead;
        while (shortHead != nullptr) {
            auto sum = longHead->val + shortHead->val + c;
            longHead->val = sum % 10;
            c = sum / 10;

            pre = pre->next;
            longHead = longHead->next;
            shortHead = shortHead->next;
        }

        while (longHead != nullptr) {
            auto sum = longHead->val + c;
            longHead->val = sum % 10;
            c = sum / 10;

            pre = pre->next;
            longHead = longHead->next;
        }
        if (c == 1) {
            pre->next = new ListNode(1);
        }

        pre = nullptr;
        auto* curr = resultHead.next;
        while (curr != nullptr) {
            auto* tmp = curr;
            curr = curr->next;
            tmp->next = pre;
            pre = tmp;
        }
        return pre;
    }
};