#include "header.h"

class Solution {
public:
    TreeNode* getLeftMostNode(TreeNode* node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    TreeNode* getRightMostNode(TreeNode* node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    void connectToLeftSubtree(TreeNode* node)
    {
        auto leftMost = getLeftMostNode(node);
        if (leftMost != nullptr) {
            leftMost->left = node->right;
            node->right    = nullptr;
        }
    }
    void connectToRightSubTree(TreeNode* node)
    {
        if (node->left != nullptr) {
            auto rightMost   = getRightMostNode(node->left);
            rightMost->right = node->right;
            node->right      = node->left;
            node->left       = nullptr;
        }
    }
    void flattenLeftToRight(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        flattenLeftToRight(node->left);
        node->right = node->left;
        node->left  = nullptr;
    }
    void flattenLeft(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        flattenLeft(node->left);
        flattenLeft(node->right);
        connectToLeftSubtree(node);
    }
    void flattenRight(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        flattenRight(node->left);
        flattenRight(node->right);
        connectToRightSubTree(node);
    }
    void flatten(TreeNode* root)
    {
        flattenRight(root);
    }
};
int main()
{
    std::vector<int> nums{1, 2, 5, 3, 4, MAGIC_INT, 6};
    auto             root = ConstructTreeFromVector(nums);
    Solution().flatten(root);
    auto res = ConstructVectorFromTree(root);
}