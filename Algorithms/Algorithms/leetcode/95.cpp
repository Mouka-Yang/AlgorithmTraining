#include "header.h"
class Solution {
public:
    using Result_T = std::vector<TreeNode*>;
    Result_T generateTrees(int n)
    {
        return n == 0 ? Result_T() : backtrack(1, n);
    }

    Result_T backtrack(int min, int max)
    {
        Result_T ret{};
        if (min > max) {
            ret.push_back(nullptr);
        }
        else if (min == max) {
            ret.push_back(new TreeNode(min));
        }
        else {
            for (int i = min; i <= max; i++) {
                auto leftTrees  = backtrack(min, i - 1);
                auto rightTrees = backtrack(i + 1, max);

                for (auto& left : leftTrees) {
                    for (auto& right : rightTrees) {
                        auto curr   = new TreeNode(i);
                        curr->left  = left;
                        curr->right = right;
                        ret.push_back(curr);
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    auto root          = new TreeNode(1);
    root->left         = new TreeNode(2);
    root->right        = new TreeNode(3);
    root->left->left   = new TreeNode(4);
    root->left->right  = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // auto test = Solution().CloneTree(root);
    Solution().generateTrees(3);
}