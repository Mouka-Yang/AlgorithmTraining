#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        std::unordered_set<int> storedNode { head->val };

        ListNode* pre = head;
        ListNode* current = head->next;

        while (current != nullptr) {
            auto tmp = current;
            while (current != nullptr && storedNode.count(current->val) == 1) {
                // duplicated node
                current = current->next;
            }
            if (current != tmp) {
                pre->next = current;
                if (current == nullptr) {
                    break;
                }
            }
            storedNode.insert(current->val);

            pre = current;
            current = current->next;
        }

        return head;
    }
};