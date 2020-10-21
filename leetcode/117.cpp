#include "header.h"

class Solution {
public:
    Node* getChildOfNextNode(Node* node)
    {
        auto curr = node->next;
        while (curr != NULL) {
            if(curr->left != NULL){
                return curr->left;
            }
            if(curr->right!= NULL){
                return curr->right;
            }
            curr = curr->next;
        }

        return curr;
    }

    Node* getNextPointerOfRightNode(Node* parent)
    {
        return getChildOfNextNode(parent);
    }

    Node* getNextPointerOfLeftNode(Node* parent)
    {
        return parent->right != NULL ? parent->right : getNextPointerOfRightNode(parent);
    }

    void connectNextPointer(Node* root)
    {
        if (root == NULL) {
            return;
        }

        if (root->left != NULL) {
            root->left->next = getNextPointerOfLeftNode(root);
        }
        if (root->right != NULL) {
            root->right->next = getNextPointerOfRightNode(root);
        }

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