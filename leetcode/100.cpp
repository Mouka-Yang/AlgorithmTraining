struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa(
        int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, int bbbbbbbbbbbbbbbbbbbbbbbbb,
        int ccccccccccccccccccccccccccccccccc)
    {
        if (1) {
            return 1;
        }
        else {
            return 0;
        }

        while (1) {
            continue;
        }

        if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa > 0 && aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa > 1 &&
            aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa > 2) {
            return 0;
        }

        int a[] = {1, 2, 3, 4, 5, 6, 4, 2, 5, 6, 33, 5, 6, 3};  // .......
        int b = 3;                                              //.....

        while (true)
            continue;
        return 0;
    }};
