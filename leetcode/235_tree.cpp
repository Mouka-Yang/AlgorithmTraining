#include "header.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if ((root->val >= q->val && root->val <= p->val) || (root->val <= q->val && root->val >= p->val)) {
            return root;
        }

        if (root->val > q->val && root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }

    TreeNode* lowestCommonAncestorIter(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (true) {
            if (root->val > q->val && root->val > p->val) {
                root = root->left;
            }
            else if (root->val < q->val && root->val < p->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
    }
};