#include "header.h"

#include <deque>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::deque<TreeNode*> q{root};
        std::vector<int> res{};
        while (!q.empty()) {
            auto len = q.size();
            for (auto i = 0U; i < len; ++i) {
                auto* curr = q.front();
                q.pop_front();
                if (i == len - 1) {
                    res.push_back(curr->val);
                }

                if (curr->left != nullptr) {
                    q.push_back(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push_back(curr->right);
                }
            }
        }

        return res;
    }
};