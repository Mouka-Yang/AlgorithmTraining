#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isEqualNode(TreeNode *m, TreeNode *n)
    {
        return (m == nullptr && n == nullptr) || (m != nullptr && n != nullptr && m->val == n->val);
    }
    bool compareNode(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (isEqualNode(leftNode, rightNode)) {
            if (leftNode == nullptr) {
                return true;
            } else {
                return compareNode(leftNode->left, rightNode->right) && compareNode(leftNode->right, rightNode->left);
            }
        }

        return false;
    }
    bool isSymmetric(TreeNode *root) { return root == nullptr || compareNode(root->left, root->right); }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = nullptr;
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(2);
    root->right->left = nullptr;
    root->right->right = new TreeNode(3);

    Solution().isSymmetric(root);
}