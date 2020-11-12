#include "header.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        std::vector<int> res1;
        std::vector<int> res2;
        traversal(root1, res1);
        traversal(root2, res2);

        std::vector<int> res(res1.size() + res2.size());

        std::merge(res1.cbegin(), res1.cend(), res2.cbegin(), res2.cend(), res.begin());

        return res;
    }
    void traversal(TreeNode* root, std::vector<int>& res)
    {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
};
