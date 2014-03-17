#include "minheap.h"

// Constructor
MinHeap::MinHeap()
{
	root = NULL;
	size = 1;
}

// Delete all nodes from the MinHeap
MinHeap::~MinHeap()
{
	free(root);
}

// Helper function for the deconstructor
void MinHeap::free(Node*& root)
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

// Insert a node 
void MinHeap::insert(const int & data)
{
	string s = "";
	// Get the binary location of the node to be inserted
	toBinary(size, s);
	// Iterator for traversing the heap (left, right)
	int i = 0;
	insertHelper(root, data, s, i);
}

// Helper function for the insert
void MinHeap::insertHelper(Node*& cur, const int & data, const string & s, int i)
{
	if (cur == NULL)
	{
		Node* newNode = new Node;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = data;
		cur = newNode;
		size++;
		return;
	}
	else
	{
		// Check the bits, 0 for left and 1 for right
		if (s[i] - 48 == 0)
			insertHelper(cur->left, data, s, ++i);
		else if (s[i] - 48 == 1)
			insertHelper(cur->right, data, s, ++i);
		// Percolate up
		percolateUP(cur);
	}
}

// Percolate the min value to satisfy MinHeap property
void MinHeap::percolateUP(Node *& cur)
{
	if (cur->left != NULL && cur->data > cur->left->data)
	{
		swap(cur, cur->left);
	}
	else if (cur->right != NULL && cur->data > cur->right->data)
	{
		swap(cur, cur->right);
	}
}

// Swap the value of two nodes
void MinHeap::swap(Node*& a, Node*& b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

// Find the minimum element (root)
int MinHeap::findMin()
{
	return root->data;
}

// Delete the root element
bool MinHeap::deleteMin()
{
	if (isEmpty() || size == 2)
		return false;
	size--;
	string s = "";
	toBinary(size, s);
	int i = 0;
	removeLast(root, s, i);
	percolateDown(root);
	return true;
}

// Remove the last element and place it in the root
void MinHeap::removeLast(Node*& cur, string s, int i)
{
	if (cur->left == NULL && cur->right == NULL)
	{
		root->data = cur->data;
		delete cur;
		cur = NULL;
		return;
	}
	else if (s[i] - 48 == 0)
		removeLast(cur->left, s, ++i);
	else if (s[i] - 48 == 1)
		removeLast(cur->right, s, ++i);
}

// Percolate the min value to satisfy MinHeap property
void MinHeap::percolateDown(Node *& cur)
{
	if (cur->left != NULL && cur->right != NULL)
	{
		if (cur->left->data < cur->right->data && cur->data > cur->left->data)
		{
			swap(cur, cur->left);
			percolateDown(cur->left);
		}
		else if (cur->left->data > cur->right->data && cur->data > cur->right->data)
		{
			swap(cur, cur->right);
			percolateDown(cur->right);
		}
	}
}

// Convert from decimal to binary to traverse 
// the tree and to keep it balanced
void MinHeap::toBinary(int decimal, string &s) 
{
	int remainder;
	if (decimal <= 1)
		return;
	remainder = decimal % 2;
	toBinary(decimal >> 1, s);
	if (remainder == 1)
		s.append("1");
	else
		s.append("0");
}

// Display the heap
void MinHeap::display()
{
	inOrder(root);
	cout << endl;
}

// Display the MinHeap in order
void MinHeap::inOrder(Node *& cur)
{
	if (cur == NULL)
		return;
	inOrder(cur->left);
	cout << cur->data << " ";
	inOrder(cur->right);
}

// Check if the MinHeap is empty
bool MinHeap::isEmpty()
{
	return root == NULL;
}
