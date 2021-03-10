#include "header.h"

#include <deque>

class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        std::deque<TreeNode*> q{root};
        auto level = 0;
        auto count = 0U;
        while (!q.empty()) {
            auto len = q.size();
            count += len;
            for (auto i = 0U; i < len; ++i) {
                auto curr = q.front();
                q.pop_front();

                if (curr->left == nullptr || curr->right == nullptr) {
                    return curr->left == nullptr ? count + q.size() : count + q.size() + 1;
                }

                q.push_back(curr->left);
                q.push_back(curr->right);
            }
        }

        return 0;
    }
};