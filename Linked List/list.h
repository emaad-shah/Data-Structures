//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Linked List: Insert, Delete, Remove, Print
//------------------------------------------------------------
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
// To detect  memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


using namespace std;


class List
{
public:
	// Constructor
	List();
	// Deconstructor
	~List();
	// Insert a node 
	bool insert(int);
	// Insert node recursively
	void rInsert(int);
	// Delete a node
	bool deleteNode(int);
	// Remove all nodes with particular number
	void removeAll(int);
	// Display the list
	void print();
	// Delete the list
	void free();
private:
	struct Node
	{
		Node* next;
		int data;
	};
	Node *head;
	
	void rInsertHelper(Node*&, int);
};


#endif

