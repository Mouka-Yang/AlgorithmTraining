#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "header.h"
using namespace testing;

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root)
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

            if (node->right) {
                s.push_back(node->right);
            }

            if (node->left) {
                s.push_back(node->left);
            }
        }

        return res;
    }

    std::vector<int> res{};
};

TEST(A, A)
{
    auto root = ConstructTreeFromVector({1, MAGIC_INT, 2, 3, MAGIC_INT});

    EXPECT_EQ(Solution().preorderTraversal(root), std::vector<int>({1, 2, 3}));
}
