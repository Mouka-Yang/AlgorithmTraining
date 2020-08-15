#include <cmath>

#include "header.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return results_;

        auto queue = std::deque<TreeNode*>{};
        queue.push_back(root);
        while (!queue.empty()) {
            auto levelNum = queue.size();
            for (int i = 0; i < levelNum; i++) {
                auto node = queue.front();
                queue.pop_front();
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
                currentResult_.push_back(node->val);
            }
            results_.push_back(currentResult_);
            currentResult_.clear();
        }
        return results_;
    }

private:
    std::vector<std::vector<int>> results_{};
    std::vector<int>              currentResult_{};
    int                           currentPosition = 0;
};