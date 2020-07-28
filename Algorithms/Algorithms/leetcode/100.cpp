struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
class Solution {
public:
    bool compareSubtree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return p->val == q->val && compareSubtree(p->left, q->left) && compareSubtree(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return compareSubtree(p, q);
    }
};