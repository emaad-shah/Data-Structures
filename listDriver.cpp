#include "list.h"

int main(void)
{
	List l1;
	// Test recursive insert
	for (int i = 5; i > 0; i--)
	{
		l1.rInsert(i);
	}

	// Testing iterative insert
	for (int i = 0; i >= -5; i--)
	{
		l1.insert(i);
	}
	l1.insert(4);
	l1.insert(4);
	l1.insert(4);
	// Test removeAll
	l1.removeAll(4);
	// Test Delete
	l1.deleteNode(1);
	l1.deleteNode(3);
	l1.deleteNode(3);
	l1.deleteNode(-3);
	l1.deleteNode('e');
	l1.print();
	l1.free();
	l1.print();

	// Test List Reverse
	l1.insert(5);
	l1.insert(15);
	l1.insert(1);
	l1.insert(7);
	l1.insert(50);
	l1.reverse();
	l1.print();
	l1.free();
	// Detect memory  leak
	//_CrtDumpMemoryLeaks();
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(141);
	system("pause");
	return 0;
}
