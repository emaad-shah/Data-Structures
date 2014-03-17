#include "stack.h"

int main(void)
{
	// Create an empty stack
	Stack s;
	
	// Push in to the stack
	s.push(2);
	s.push(5);

	// Peek
	cout << "Peek at the top of the stack: ";
	cout << s.peek() << endl;

	// Pop from the stack
	s.pop();
	s.pop();
	s.pop();

	// Peek again
	cout << "Peek at the top of the stack: ";
	cout << s.peek() << endl;

	// Push
	s.push(100);
	
	// Peek
	cout << "Peek at the top of the stack: ";
	cout << s.peek() << endl;

	system("pause");
	return 0;
}



