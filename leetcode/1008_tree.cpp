#include "header.h"

class Solution {
public:
    TreeNode* bstFromPreorder1(const std::vector<int>& preorder)
    {
        if (preorder.empty()) {
            return nullptr;
        }
        auto* root = new TreeNode(preorder[0]);
        std::vector<TreeNode*> s{root};
        for (auto i = 1U; i < preorder.size(); ++i) {
            auto* curr = new TreeNode(preorder[i]);
            if (preorder[i] < s.back()->val) {
                s.back()->left = curr;
            }
            else {
                TreeNode* parent = nullptr;
                while (!s.empty() && s.back()->val < preorder[i]) {
                    parent = s.back();
                    s.pop_back();
                }
                parent->right = curr;
            }
            s.push_back(curr);
        }

        return root;
    }

    TreeNode* bstFromPreorder(const std::vector<int>& preorder)
    {
        return build(preorder, 0, preorder.size());
    }

    TreeNode* build(const std::vector<int>& preorder, int l, int r)
    {
        if (r == l) {
            return nullptr;
        }
        if (r - l == 1) {
            return new TreeNode(preorder[l]);
        }

        auto rightBegin = r;
        for (auto i = l + 1; i < r; ++i) {
            if (preorder[i] > preorder[l]) {
                rightBegin = i;
                break;
            }
        }
        auto* root = new TreeNode(preorder[l]);
        root->left = build(preorder, l + 1, rightBegin);
        root->right = build(preorder, rightBegin, r);

        return root;
    }
};