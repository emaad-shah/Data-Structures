//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Stack:     A collection of zero or more items (list) with 
//	      the restriction that all insertions and removals
//            take place at only one end, called the top of 
//            the stack 
//------------------------------------------------------------

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <list>

using namespace std;

class Stack
{
	public:
		// Stack Constructor
		Stack();
		// Push an item at the top of the stack
		bool push(int);
		// Pop an item from the top of the stack
		bool pop();
		// Check if a stack is empty
		bool isEmpty();
		// Check if a stack is full
		bool isFull();
		// Peek the top of the stack
		int peek();

	private:
		// List storing stack of integers
		list<int> stack;
		// Max Size of the Stack
		const int max = 10;
		// Current size of the Stack
		int size;
};

#endif
