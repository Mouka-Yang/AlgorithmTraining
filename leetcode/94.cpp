#include "header.h"
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> keptNodes;

        auto curr = root;
        while (!keptNodes.empty() || curr != nullptr) {
            if (curr != nullptr) {
                keptNodes.push(curr);
                curr = curr->left;
            }
            else {
                curr = keptNodes.top();
                keptNodes.pop();
                result_.push_back(curr->val);
                curr = curr->right;
            }
        }

        return result_;
    }

private:
    std::vector<int> result_{};
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

    Solution().inorderTraversal(root);
}