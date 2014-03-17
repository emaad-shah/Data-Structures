//------------------------------------------------------------
// Copyright: Syed Shah 2014
// MinHeap:   Insert, Delete 
//------------------------------------------------------------

#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class MinHeap
{
	public:
		// Constructor
		MinHeap();
		// Delete all nodes from the MinHeap
		~MinHeap();
		// Insert a node 
		void insert(const int &);
		// Check if the MinHeap is empty
		bool isEmpty();
		// Display the heap
		void display();
		// Convert from decimal to binary
		void toBinary(int, string&);
		// Find the minimum element (root)
		int findMin();
		// Delete the root element
		bool deleteMin();

	private:
		struct Node
		{
			Node* left;
			Node* right;
			int data;
		};
		Node *root;
	
		// Size of the tree
		int size;

		// Helper function for the insert
		void insertHelper(Node*&, const int &, const string &, int);
		// Percolate the min value to satisfy MinHeap property
		void percolateUP(Node *&);
		// Percolate the min value to satisfy MinHeap property
		void percolateDown(Node *&);
		// Swap the value of two nodes
		void swap(Node*&, Node*&);
		// Display the MinHeap in order
		void inOrder(Node*&);
		// Remove the last element and place it in the root
		void removeLast(Node*& cur, string, int);
		// Helper function for the deconstructor
		void free(Node*&);
};

#endif
