#include "header.h"

class MyLessCompare {
public:
    bool operator()(int x, int y)
    {
        return x < y;
    }
};
class Solution {
public:
    void inorder(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        results_.push_back(node->val);
        inorder(node->right);
    }

    bool isValidBST(TreeNode* root)
    {
        inorder(root);

        return std::is_sorted(results_.begin(), results_.end(), std::less_equal<int>());
    }

private:
    std::vector<int> results_{};
};
