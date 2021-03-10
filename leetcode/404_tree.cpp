#include "header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        std::vector<TreeNode*> s{root};
        auto sum = 0;
        while (!s.empty()) {
            auto* node = s.back();
            s.pop_back();

            if (node->right != nullptr) {
                s.push_back(node->right);
            }

            if (node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr) {
                    sum += node->left->val;
                }
                s.push_back(node->left);
            }
        }

        return sum;
    }
};