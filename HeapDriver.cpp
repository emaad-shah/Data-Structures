#include "minheap.h"

int main(void)
{
	// Create a heap object
	MinHeap m, m2;

	// Tese Case 1
	m.insert(15);
	m.insert(2);
	m.insert(1);
	m.insert(7);
	m.insert(6);
	m.display();
	m.deleteMin();
	cout << endl;

	// Test Case 2
	m2.insert(1);
	m2.deleteMin();
	m2.insert(3);
	m2.insert(6);
	m2.insert(5);
	m2.insert(9);
	m2.insert(8);
	m2.display();
	m2.deleteMin();
	m2.display();

	system("pause");
	return 0;
}



