#include "header.h"

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == q || root == p) {
      return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
      return root;
    }

    if (left != nullptr) {
      return left;
    }

    return right;
  }
};