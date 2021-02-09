#include "header.h"

class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
    bool isEnd(TreeNode* node, int remain)
    {
        return remain == node->val;
    }
    void count(TreeNode* node, int remain)
    {
        if (node != nullptr) {
            currentResult_.push_back(node->val);
            if (isEnd(node, remain) && isLeaf(node)) {
                results_.push_back(currentResult_);
            }
            else {
                count(node->left, remain - node->val);
                count(node->right, remain - node->val);
            }
            currentResult_.pop_back();
        }
    }
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
    {
        count(root, sum);
        return results_;
    }

    std::vector<std::vector<int>> pathSum_dfs(TreeNode* root, int targetSum) {
      dfs(root, targetSum);
      return results_;
    }

    void dfs(TreeNode* node, int remain) {
      remain -= node->val;
      currentResult_.push_back(node->val);
      if (remain == 0 && node->left == nullptr && node->right == nullptr) {
        results_.push_back(currentResult_);
        currentResult_.pop_back();
        return;
      }

      if (node->left) {
        dfs(node->left, remain);
      }

      if (node->right) {
        dfs(node->right, remain);
      }

      currentResult_.pop_back();
    }

   private:
    std::vector<std::vector<int>> results_{};
    std::vector<int>              currentResult_{};
};

int main()
{
    // TreeNode* root         = new TreeNode(1);
    // root->left             = new TreeNode(-2);
    // root->right            = new TreeNode(-3);
    // root->left->left       = new TreeNode(1);
    // root->left->right      = new TreeNode(3);
    // root->left->left->left = new TreeNode(-1);

    // Solution().pathSum(root, -1);
    std::vector<int> nums =
        std::vector<int>{5, 4, 8, 11, MAGIC_INT, 13, 4, 7, 2, MAGIC_INT, MAGIC_INT, 5, 1};
    TreeNode* root  = ConstructTreeFromVector(nums);
    auto      nodes = ConstructVectorFromTree(root);
    DeleteTree(root);
}