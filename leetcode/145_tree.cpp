#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        if (!root) {
            return {};
        }

        std::vector<TreeNode*> s{};

        s.push_back(root);
        while (!s.empty()) {
            auto node{s.back()};
            s.pop_back();

            res.push_back(node->val);

            if (node->left) {
                s.push_back(node->left);
            }

            if (node->right) {
                s.push_back(node->right);
            }
        }

        return {res.crbegin(), res.crend()};
    }

    std::vector<int> res{};
};
