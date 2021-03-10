#include "header.h"

class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode* head)
    {
        auto* curr = head;
        ListNode* tail = nullptr;
        auto len = 0;
        while (curr != nullptr) {
            auto* next = curr->next;
            curr->next = tail;
            tail = curr;
            curr = next;
            ++len;
        }

        std::vector<int> result(len, 0);
        std::vector<int> stack{};
        curr = tail;
        while (len >= 1) {
            while (!stack.empty() && stack.back() <= curr->val) {
                stack.pop_back();
            }

            result[len - 1] = stack.empty() ? 0 : stack.back();

            stack.push_back(curr->val);
            curr = curr->next;
            --len;
        }

        return result;
    }
};