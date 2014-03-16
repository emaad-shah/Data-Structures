#include "bstree.h"

// Constructor
BSTree::BSTree()
{
	// Initialize the BSTree
	root = NULL;
}

// Delete all nodes from the BSTree
BSTree::~BSTree()
{
	free(root);
}

// Helper function for the deconstructor
void BSTree::free(Node*& root)
{
	if (root == NULL)
		return;
	else
	{
		free(root->left);
		free(root->right);
		delete root;
		root = NULL;
	}
}

// Insert a node in the tree
bool BSTree::insert(const int & data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	// Out of memory, bail
	if (newNode == NULL)
		return false;
	// Tree is empty
	if (root == NULL)
	{
		root = newNode;
		return true;
	}

	Node* cur = root;
	while (true)
	{
		// Once is enough
		if (data == cur->data)
		{
			delete newNode;
			break;
		}

		// Traverse left sub-tree
		else if (data < cur->data)
		{
			if (cur->left == NULL)
			{
				cur->left = newNode;
				break;
			}
			else
				cur = cur->left;
		}
		// Traverse right sub-tree
		else
		{
			if (cur->right == NULL)
			{
				cur->right = newNode;
				break;
			}
			else
				cur = cur->right;
		}
	}
	return true;
}

// Count number of leaves in the BSTree
int BSTree::countLeaves()
{
	return countLeavesHelper(root) - 1;
}

// Count Leaves Helper function
int BSTree::countLeavesHelper(Node*& cur)
{
	if (cur == NULL)
		return 0;
	return countLeavesHelper(cur->left) + 1 +
		countLeavesHelper(cur->right);

}

void BSTree::print()
{
	inOrder(root);
}

// Display the tree in order
void BSTree::inOrder(Node *& cur)
{
	if (cur == NULL)
		return;
	inOrder(cur->left);
	cout << cur->data << endl;
	inOrder(cur->right);
}

// Find the least common ancestor between two nodes
void BSTree::lca(int a, int b)
{
	int n = 0;
	if (b < a)
	{
		// Swap
		a = a + b;
		b = a - b;
		a = a - b;
	}

	// Call LCA Helper Function
	lcaHelper(root, a, b, n);
	cout << "Least common ancestor of " << a << " and " << b << ": ";
	cout << n << endl;
}

// Helper function to find the least common ancestor
void BSTree::lcaHelper(Node*& cur, const int & a, const int & b, int &n)
{
	if (cur == NULL)
		return;
	else
	{
		if (a < cur->data && b < cur->data)
			lcaHelper(cur->left, a, b, n);
		else if (a > cur->data && b > cur->data)
			lcaHelper(cur->right, a, b, n);
		else if (a == cur->data && cur->right != NULL && b == cur->right->data)
				n = a;
		else if (b == cur->data && cur->left != NULL && a == cur->left->data)
				n = b;
		else if (a < cur->data && b > cur->data)
		{
			bool getA = retrieve(cur->left, a);
			bool getB = retrieve(cur->right, b);
			if (getA && getB)
				n = cur->data;
			lcaHelper(cur->left, a, b, n);
			lcaHelper(cur->right, a, b, n);
		}
	}
}

// Check if data exists in the BSTree
bool BSTree::retrieve(Node*& cur, const int & n)
{
	if (cur == NULL)
		return false;
	else
	{
		if (n == cur->data)
			return true;
		else if (n < cur->data)
			retrieve(cur->left, n);
		else if (n > cur->data)
			retrieve(cur->right, n);
	}
}
