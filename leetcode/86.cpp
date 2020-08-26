#include "header.h"
class Solution {
public:
    bool greater(int num, int target)
    {
        return num >= target;
    }
    ListNode* partition(ListNode* head, int x)
    {
        using namespace std::placeholders;
        auto pre     = new ListNode(0, head);
        auto preHead = pre;
        auto curr    = head;

        while (curr != nullptr && !greater(curr->val, x)) {
            curr = curr->next;
            pre  = pre->next;
        }

        auto ustart = curr;
        auto uend   = pre;
        while (curr != nullptr) {
            uend->next = curr;
            uend       = curr;
            while (uend->next != nullptr && greater(uend->next->val, x)) {
                uend = uend->next;
            }

            if (uend->next == nullptr)
                break;

            auto lstart = uend->next;
            auto lend   = lstart;
            while (lend->next != nullptr && !greater(lend->next->val, x)) {
                lend = lend->next;
            }

            pre->next  = lstart;
            uend->next = lend->next;
            lend->next = ustart;

            curr = uend->next;
            pre  = lend;
        }

        return preHead->next;
    }
};

int main()
{
    auto list = ConstructList(std::vector<int>{1, 4, 3, 2, 5, 2});
    PrintList(Solution().partition(list, 3));
    DeleteList(list);
}