/*
Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* buildSubTree(vector<int>& preorder, int preStart, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mymap) {
        if (inStart > inEnd)
            return NULL;

        auto rootVal = preorder[preStart];
        auto root = new TreeNode(rootVal);
        auto rootPos = mymap[rootVal];

        root->left = buildSubTree(preorder, preStart + 1, inorder, inStart, rootPos - 1, mymap);
        root->right = buildSubTree(preorder, preStart + rootPos - inStart + 1, inorder, rootPos + 1, inEnd, mymap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < inorder.size(); i++) {
            mymap[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, inorder, 0, inorder.size() - 1, mymap);
    }
};

int main() {
    vector<int> pre = {-1};
    vector<int> in = {-1};
    Solution().buildTree(pre, in);
}