#include "header.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head)
    {
        if (head == nullptr) {
            return nullptr;
        }

        auto* curr = head;

        while (curr != nullptr) {
            if (curr->child == nullptr) {
                curr = curr->next;
                continue;
            }

            auto* childHead = curr->child;
            auto* childTail = childHead;
            while (childTail->next != nullptr) {
                childTail = childTail->next;
            }

            childTail->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = childTail;
            }

            curr->next = childHead;
            childHead->prev = curr;
        }

        return head;
    }
};