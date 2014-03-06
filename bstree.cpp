#include "bstree.h"


BSTree::BSTree()
{
	root = NULL;
}


// Deconstructor
BSTree::~BSTree()
{
	free(root);
}

// Delete all nodes
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
bool BSTree::insert(int data)
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

// Count number of leaves
int BSTree::countLeaves()
{
	return countLeavesHelper(root);
}

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

int main(void)
{
	// Create an empty tree
	BSTree t;
	// Test Insert
	t.insert(20);
	t.insert(4);
	t.insert(7);
	t.insert(31);
	t.insert(5);
	t.print();

	cout << "Number of leaves: " << t.countLeaves() << endl;
	// Detect memory  leak
	//_CrtDumpMemoryLeaks();
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(141);
	system("pause");
	return 0;
}
 


