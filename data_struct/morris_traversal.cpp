#include "../leetcode/header.h"
#include "gtest/gtest.h"

class Solution {
public:
    TreeNode* getRightMostNodeOfLeftTree(TreeNode* node)
    {
        if (node == nullptr || node->left == nullptr) {
            return nullptr;
        }

        auto curr{node->left};
        while (curr->right != nullptr && curr->right != node) {
            curr = curr->right;
        }

        return curr;
    }

    std::vector<int> inorderTraversal(TreeNode* root)
    {
        auto curr = root;
        std::vector<int> res{};
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto rightMostNode = getRightMostNodeOfLeftTree(curr);
                if (rightMostNode->right == curr) {
                    rightMostNode->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    rightMostNode->right = curr;
                    curr = curr->left;
                }
            }
            else {
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};

TEST(SolutionTest, Test)
{
    std::vector<int> tree{10, 5, 30, -2, 6, MAGIC_INT, 40, MAGIC_INT, MAGIC_INT, MAGIC_INT, 8};
    auto root = ConstructTreeFromVector(tree);
    EXPECT_EQ(Solution().inorderTraversal(root), std::vector<int>({-2, 5, 6, 8, 10, 30, 40}));
}
