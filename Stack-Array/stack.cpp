#include "stack.h"

// Stack Constructor
Stack::Stack()
{
	// Point the iterator at 
	// the end of the stack
	itr = max - 1;
	// Initialize the stack
	for (int i = 0; i < max; i++)
		stack[i] = -1;
}

// Push an item at the top of the stack
bool Stack::push(int item)
{
	if (!isFull())
	{
		stack[itr--] = item;
		return true;
	}
	return false;
}

// Pop an item from the top of the stack
bool Stack::pop()
{
	if (!isEmpty())
	{
		stack[itr++] = -1;
		return true;
	}
	return false;
}

// Check if a stack is full
bool Stack::isFull()
{
	return itr == 0;
}

// Check if a stack is empty
bool Stack::isEmpty()
{
	return itr == max - 1;
}

// Peek the top of the stack
// Return -1 if stack is empty
int Stack::peek()
{
	if (!isEmpty())
		return stack[itr + 1];
	return -1;
}
