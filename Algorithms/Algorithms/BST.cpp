#include "common.h"
#include "BST.h"

Node* InsertNode(Node* root, int key) {
	if (!root)	return new Node(key);

	if (root->Key > key)
		root->LeftChild = InsertNode(root->LeftChild, key);
	else if (root->Key < key)
		root->RightChild = InsertNode(root->RightChild, key);

	// If there are duplicates, just return
	return root;
}

Node* SearchNode(Node* root, int key) {
	if (!root)	return NULL;

	if (root->Key = key)
		return root;
	else if (root->Key < key)
		return SearchNode(root->RightChild, key);
	else
		return SearchNode(root->LeftChild, key);
}

Node* MinNode(Node* root) {
	if (!root)	return NULL;

	Node* min = root;
	while (min->LeftChild)
		min = min->LeftChild;

	return min;
}

Node* DeleteNode(Node* root, int key) {
	if (!root)	return NULL;

	Node* newRoot = root;
	if (root->Key < key)
		root->RightChild = DeleteNode(root->RightChild, key);
	else if (root->Key > key)
		root->LeftChild = DeleteNode(root->LeftChild, key);
	else {
		// Found node to be deleted
		if (!root->LeftChild) {
			newRoot = root->RightChild;
			delete root;
		}
		else if (!root->RightChild) {
			newRoot = root->LeftChild;
			delete root;
		}
		else {
			// the Node deleted has two child
			/*Node* min = MinNode(root->RightChild);
			root->Key = min->Key;
			root->RightChild = DeleteNode(root->RightChild, min->Key);*/

			Node *min = root->RightChild, *minParent = root->RightChild;
			while (min->LeftChild) {
				minParent = min;
				min = min->LeftChild;
			}

			minParent->LeftChild = min->RightChild;
			root->Key = min->Key;

			delete min;
		}
	}
	return newRoot;
}

/*************** Balanced Binary Search Tree (AVL Tree) ***************************/

int GetNodeHeight(Node* root) {
	return root ? root->Height : 0;
}

/*
T1, T2, T3 and T4 are subtrees.
		 z                                      y
		/ \                                   /   \
	   y   T4      Right Rotate (z)          x      z
	  / \          - - - - - - - - ->      /  \    /  \
	 x   T3                               T1  T2  T3  T4
	/ \
  T1   T2
*/
Node* RightRotate(Node *root) {
	Node* newRoot = root->LeftChild;
	Node* tmpTree = newRoot->RightChild;

	newRoot->RightChild = root;
	root->LeftChild = tmpTree;

	root->Height = 1 + max(GetNodeHeight(root->LeftChild), GetNodeHeight(root->RightChild));
	newRoot->Height = 1 + max(GetNodeHeight(newRoot->LeftChild), GetNodeHeight(root->RightChild));

	return newRoot;
}

/*
  z                                y
 /  \                            /   \
T1   y     Left Rotate(z)       z      x
	/  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
	   / \
	 T3  T4
*/
Node* LeftRotate(Node *root) {
	Node* newRoot = root->RightChild;
	Node* tmpTree = newRoot->LeftChild;

	newRoot->LeftChild = root;
	root->RightChild = tmpTree;

	root->Height = 1 + max(GetNodeHeight(root->LeftChild), GetNodeHeight(root->RightChild));
	newRoot->Height = 1 + max(GetNodeHeight(newRoot->LeftChild), GetNodeHeight(root->RightChild));

	return newRoot;
}

int GetBalanceFactor(Node* root) {
	return GetNodeHeight(root->LeftChild) - GetNodeHeight(root->RightChild);
}

/*
* Solution for inserting to AVL_tree:

1) Perform the normal BST insertion.

2) The current node must be one of the ancestors of the newly inserted node.
Update the height of the current node.
3) Get the balance factor (left subtree height ¨C right subtree height) of the current node.

4) If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or left Right case.
To check whether it is left left case or not, compare the newly inserted key with the key in left subtree root.

5) If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right-Left case.
To check whether it is Right Right case or not, compare the newly inserted key with the key in right subtree root.

*/
Node* BalanceInsertNode(Node *root, int key) {
	if (!root)	return new Node(key);

	if (root->Key > key) {
		root->LeftChild = BalanceInsertNode(root->LeftChild, key);
	}
	else if (root->Key < key) {
		root->RightChild = BalanceInsertNode(root->RightChild, key);
	}
	else
		return root;

	root->Height = 1 + max(GetNodeHeight(root->LeftChild), GetNodeHeight(root->RightChild));

	Node* newRoot = root;
	int factor = GetBalanceFactor(root);
	if (factor > 1) {
		if (root->LeftChild->Key > key) {
			// Left-Left case
			newRoot = RightRotate(root);
		}
		else {
			// Left-Right case
			root->LeftChild = LeftRotate(root->LeftChild);
			newRoot = RightRotate(root);
		}
	}
	else if (factor < -1) {
		if (root->RightChild->Key < key) {
			// Right-Right case
			newRoot = LeftRotate(root);
		}
		else {
			// Right-Left case
			root->RightChild = RightRotate(root->RightChild);
			newRoot = LeftRotate(root);
		}
	}

	return newRoot;
}

/*

1) Perform the normal BST deletion.

2) The current node must be one of the ancestors of the deleted node.
Update the height of the current node.

3) Get the balance factor (left subtree height ¨C right subtree height) of the current node.

4) If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or Left Right case.
To check whether it is Left Left case or Left Right case, get the balance factor of left subtree.
If balance factor of the left subtree is greater than or equal to 0, then it is Left Left case, else Left Right case.

5) If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right Left case.
To check whether it is Right Right case or Right Left case, get the balance factor of right subtree.
If the balance factor of the right subtree is smaller than or equal to 0, then it is Right Right case, else Right Left case.

*/
Node* BalanceDeleteNode(Node* root, int key) {
	if (!root)	return NULL;

	Node* newRoot = root;
	if (root->Key < key)
		root->RightChild = DeleteNode(root->RightChild, key);
	else if (root->Key > key)
		root->LeftChild = DeleteNode(root->LeftChild, key);
	else {
		// Found node to be deleted
		if (!root->LeftChild) {
			newRoot = root->RightChild;
			delete root;
		}
		else if (!root->RightChild) {
			newRoot = root->LeftChild;
			delete root;
		}
		else {
			// the Node deleted has two child
			Node *min = root->RightChild, *minParent = root->RightChild;
			while (min->LeftChild) {
				minParent = min;
				min = min->LeftChild;
			}

			minParent->LeftChild = min->RightChild;
			root->Key = min->Key;

			delete min;
		}
	}

	// After deletion, Re-balance AVL tree

	if (!newRoot)	return NULL;

	newRoot->Height = 1 + max(GetNodeHeight(newRoot->LeftChild), GetNodeHeight(newRoot->RightChild));

	int factor = GetBalanceFactor(newRoot);
	if (factor > 1) {
		int leftFactor = GetBalanceFactor(newRoot->LeftChild);
		if (leftFactor >= 0) {
			// Left-Left case
			newRoot = RightRotate(newRoot);
		}
		else {
			// Left-Right case
			newRoot->LeftChild = LeftRotate(newRoot->LeftChild);
			newRoot = RightRotate(newRoot);
		}
	}
	else if (factor < -1) {
		int rightFactor = GetBalanceFactor(newRoot->RightChild);
		if (rightFactor <= 0) {
			// Right-Right case
			newRoot = LeftRotate(newRoot);
		}
		else {
			// Right-Left case
			newRoot->RightChild = RightRotate(newRoot->RightChild);
			newRoot = LeftRotate(newRoot);
		}

	}
	return newRoot;
}

void PreOrder(Node* root) {
	if (!root)	return;

	cout << setw(3) << root->Key;
	PreOrder(root->LeftChild);
	PreOrder(root->RightChild);
}

void InOrder(Node* root) {
	if (!root)	return;

	InOrder(root->LeftChild);
	cout << setw(3) << root->Key;
	InOrder(root->RightChild);
}

void PostOrder(Node* root) {
	if (!root)	return;

	PostOrder(root->LeftChild);
	PostOrder(root->RightChild);
	cout << setw(3) << root->Key;
}