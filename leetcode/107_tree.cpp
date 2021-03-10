#include "header.h"

#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> result{};
        std::deque<TreeNode*> q{root};

        while (!q.empty()) {
            auto len = q.size();
            std::vector<int> levelResult{};
            for (auto i = 0U; i < len; ++i) {
                auto* curr = q.front();
                q.pop_front();

                levelResult.push_back(curr->val);
                if (curr->left != nullptr) {
                    q.push_back(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push_back(curr->right);
                }
            }

            result.push_back(std::move(levelResult));
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};