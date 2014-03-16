#include "bstree.h"

int main(void)
{
	// Create an empty tree
	BSTree t, t2;

	// Test Insert
	t.insert(20);
	t.insert(22);
	t.insert(8);
	t.insert(4);
	t.insert(2);
	t.insert(5);
	t.insert(12);
	t.insert(10);
	t.insert(14);
	t.print();

	// Testing Count Leaves Function
	cout << endl << "Number of leaves: " << t.countLeaves() << endl << endl;

	// Testing LCA Function
	t.lca(20, 22);
	t.lca(2, 14);
	t.lca(2, 10);
	t.lca(5, 8);
	t.lca(2, 4);
	t.lca(8, 22);
	t.lca(4, 12);
	t.lca(5, 10);
	t.lca(12, 14);
	t.lca(22, 8);

	// Insert in to a different tree
	t2.insert(20);
	t2.insert(4);
	t2.insert(31);
	t2.insert(7);
	t2.insert(5);

	// Testing Count Leaves Function
	cout << endl << "Number of leaves: " << t2.countLeaves() << endl << endl;

	system("pause");
	return 0;
}



