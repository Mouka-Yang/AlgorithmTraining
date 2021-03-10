#include "header.h"

#include <cmath>

class Solution {
public:
    bool isBalance(TreeNode* root)
    {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }

        auto leftHeight = getHeight(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        auto rightHeight = getHeight(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        return std::abs(leftHeight - rightHeight) <= 1 ? 1 + std::max(leftHeight, rightHeight) : -1;
    }
};