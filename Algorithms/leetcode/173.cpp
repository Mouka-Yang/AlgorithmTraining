/*
Binary Search Tree Iterator
Medium

1325

239

Favorite

Share
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {}
};

class BSTIterator {
   private:
    stack<const TreeNode*> parents;
    void pushLeft(const TreeNode* node){
        while(node!=nullptr && node->left!=nullptr){
            parents.push(node);
            node = node->left;
        }
    }
   public:
    BSTIterator(TreeNode* root) : parents() {
        pushLeft(root);
    }

    /** @return the next smallest number */
    int next() {
        auto tmpNode = parents.top();
        parents.pop();
        pushLeft(tmpNode->right);
        return tmpNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !parents.empty();
    }
};