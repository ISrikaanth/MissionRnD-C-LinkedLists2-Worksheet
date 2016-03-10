/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node * reverseLinkedList(struct node *head) 
{
	if (head==NULL)
	    return NULL;
	int count = 0;
	struct node *t;
	t = head;
	while (t != NULL)
	{
		count++;
		t = t->next;
	}
	t = head;
	int *a;
	a = (int *)malloc(count*sizeof(int));
	while (t != NULL)
	{
		a[count - 1] = t->num;
		t = t->next;
		count--;
	}
	t = head;
	count = 0;
	while (t != NULL)
	{
		t->num = a[count];
		t = t->next;
		count++;
	}
	return head;
}
