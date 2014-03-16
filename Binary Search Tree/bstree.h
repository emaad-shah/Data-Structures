//------------------------------------------------------------
// Copyright: Syed Shah 2014
// BSTREE:    Insert, Print, Count Leaves, LCA, Retrieve 
//------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

using namespace std;

class BSTree
{
	public:
		// Constructor
		BSTree();
		// Delete all nodes from the BSTree
		~BSTree();
		// Insert a node 
		bool insert(const int &);
		void print();
		// Count number of leaves in the BSTree
		int countLeaves();
		// Find the least common ancestor between two nodes
		void lca(int, int);

	private:
		struct Node
		{
			Node* left;
			Node* right;
			int data;
		};
		Node *root;

		// Display the tree in order
		void inOrder(Node*&);
		// Count Leaves Helper function
		int countLeavesHelper(Node*&);
		// Helper function to find the least common ancestor
		void lcaHelper(Node*&, const int &, const int &, int&);
		// Check if data exists in the BSTree
		bool retrieve(Node*&, const int &);
		// Helper function for the deconstructor
		void free(Node*&);
};

#endif
