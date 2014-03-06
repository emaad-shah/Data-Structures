//------------------------------------------------------------
// Copyright: Syed Shah 2014
// BSTREE: Insert, Print
//------------------------------------------------------------
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <fstream>
// To detect  memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

class BSTree
{
public:
	// Constructor
	BSTree();
	// Deconstructor
	~BSTree();
	// Insert a node 
	bool insert(int);
	void print();
	
private:
	struct Node
	{
		Node* left;
		Node* right;
		int data;
	};
	Node *root;

	void inOrder(Node*&);
	void free(Node*&);
};

#endif
