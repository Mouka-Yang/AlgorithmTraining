#pragma once

typedef struct _Node {
	int Key;
	int Height;
	struct _Node* LeftChild;
	struct _Node* RightChild;

	_Node(int key = 0, int height = 1, struct _Node* left = NULL, struct _Node* right = NULL)
		:Key(key), Height(height), LeftChild(left), RightChild(right) {}
}Node;

Node * InsertNode(Node * root, int key);

Node * SearchNode(Node * root, int key);

Node * MinNode(Node * root);

Node * DeleteNode(Node * root, int key);

int GetNodeHeight(Node * root);

Node * RightRotate(Node * root);

Node * LeftRotate(Node * root);

int GetBalanceFactor(Node * root);

Node * BalanceInsertNode(Node * root, int key);

Node * BalanceDeleteNode(Node * root, int key);

void PreOrder(Node * root);

void InOrder(Node * root);

void PostOrder(Node * root);
