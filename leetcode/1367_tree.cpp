#include "header.h"

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        return traverse(head, root);
    }

    bool traverse(ListNode* head, TreeNode* node)
    {
        if (node == nullptr) {
            return false;
        }

        return check(head, node) || traverse(head, node->left) || traverse(head, node->right);
    }

    bool check(ListNode* node, TreeNode* root)
    {
        if (node == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }

        if (node->val == root->val) {
            return check(node->next, root->left) || check(node->next, root->right);
        }

        return false;
    }
};