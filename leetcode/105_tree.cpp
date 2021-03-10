#include "header.h"

class Solution {
 public:
  using iter = std::vector<int>::const_iterator;
  TreeNode* buildSubtree(iter pre_start, iter pre_end, iter in_start,
                         iter in_end) {
    auto *node = new TreeNode(*pre_start);
    if (pre_start != pre_end) {
      auto node_iter = std::find(in_start, in_end, node->val);
      auto left_tree_len = std::distance(in_start, node_iter);
      auto right_tree_len = std::distance(node_iter + 1, in_end);

      if (in_start != node_iter) {
        // node has left subtree
        node->left = buildSubtree(pre_start + 1, pre_start + 1 + left_tree_len,
                                  in_start, node_iter);
      }

      if (in_end - 1 != node_iter) {
        // node has right subtree
        node->right = buildSubtree(pre_start + left_tree_len + 1, pre_end,
                                   node_iter + 1, in_end);
      }
    }

    return node;
  }

  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildSubtree(preorder.cbegin(), preorder.cend(), inorder.cbegin(),
                        inorder.cend());
  }
};