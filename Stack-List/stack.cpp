#include "stack.h"

// Stack Constructor
Stack::Stack()
{
	// Initialize the stack
	size = 0;
}

// Push an item at the top of the stack
bool Stack::push(int item)
{
	if (!isFull())
	{
		stack.push_front(item);
		size++;
		return true;
	}
	return false;
}

// Pop an item from the top of the stack
bool Stack::pop()
{
	if (!isEmpty())
	{
		size--;
		stack.pop_back();
		return true;
	}
	return false;
}

// Check if a stack is empty
bool Stack::isEmpty()
{
	return size == 0;
}

// Check if a stack is full
bool Stack::isFull()
{
	return size == max;
}

// Peek the top of the stack
// Return -1 if stack is empty
int Stack::peek()
{
	if (!isEmpty())
		return *stack.begin();
	return -1;
}
