#include "header.h"

class Solution {
public:
    TreeNode* getSubtree(ListNode* start, ListNode* end)
    {
        if (start == end) {
            return nullptr;
        }
        auto fast = start;
        auto slow = start;
        auto step = 1;
        while (fast != end) {
            if (step++ % 2 == 0) {
                slow = slow->next;
            }
            fast = fast->next;
        }

        auto node   = new TreeNode(slow->val);
        node->left  = getSubtree(start, slow);
        node->right = getSubtree(slow->next, end);

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        return getSubtree(head, nullptr);
    }
};