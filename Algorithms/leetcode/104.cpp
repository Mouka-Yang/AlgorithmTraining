#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution
{
public:
    constexpr int max(int a, int b) { return a > b ? a : b; }
    int getMaxDepthRecursively(TreeNode *root)
    {
        return root == nullptr ? 0 : 1 + max(getMaxDepthRecursively(root->left), getMaxDepthRecursively(root->right));
    }

    int getMaxDepthIteratively(TreeNode *root) {}
    int maxDepth(TreeNode *root) { return getMaxDepthRecursively(root); }
};