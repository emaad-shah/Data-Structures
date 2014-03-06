//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Linked List: Reverse a Link List
//------------------------------------------------------------

#include "List.h"

// Revserse a linked list
void List::reverse()
{
	// If one or none element
	if (head == NULL || head->next == NULL)
		return;
	Node* cur = head->next;
	Node* prev = head->next;
	Node* tmp = head;
	tmp->next = NULL;
	while (cur->next != NULL)
	{
		cur = cur->next;
		prev->next = tmp;
		tmp = prev;
		prev = cur;
	}
	cur->next = tmp;
	head = cur;
}
