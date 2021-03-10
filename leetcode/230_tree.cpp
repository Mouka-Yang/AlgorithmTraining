#include "header.h"

class Solution {
public:
    int count = 0;
    int result = -1;
    bool find = false;
    int kthSmallest(TreeNode* root, int k)
    {
        inOrder(root, k);
        return result;
    }

    void inOrder(TreeNode* node, int k)
    {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left, k);

        if (result != -1) {
            return;
        }

        if (++count == k) {
            result = node->val;
            return;
        }

        inOrder(node->right, k);
    }
};