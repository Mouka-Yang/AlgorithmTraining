#include "header.h"

class Solution {
public:
    Node* getNextPointerOfRightNode(Node* parent) {
        parent->right->next = parent->next == NULL ? NULL : parent->next->left;
    }

    Node* getNextPointerOfLeftNode(Node* parent) {
        parent->left->next = parent->right;
    }

    void  connectNextPointer(Node* root)
    {
        if (root->left == NULL) {
            return;
        }

        root->left->next  = getNextPointerOfLeftNode(root);
        root->right->next = getNextPointerOfRightNode(root);

        connectNextPointer(root->left);
        connectNextPointer(root->right);
    }

    Node* connect(Node* root)
    {
        if (root == NULL) {
            return NULL;
        }

        connectNextPointer(root);

        return root;
    }
};