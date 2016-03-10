/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node * insert(struct node * first, int n);
struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	if ((head1 == NULL) && (head2 == NULL))
		return NULL;
	int flag = 0;
	struct node *t = NULL, *p;
	while ((head1 != NULL) && (head2 != NULL))
	{
		if ((head1->num) <= (head2->num))
		{
			p = insert(t, head1->num);
			if (flag == 0)
			{
				t = p;
				flag++;
			}
			head1 = head1->next;
		}
		else
		{
			p = insert(t, head2->num);
			if (flag == 0)
			{
				t = p;
				flag++;
			}
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		p = insert(t, head1->num);
		if (flag == 0)
		{
			t = p;
			flag++;
		}
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		p = insert(t, head2->num);
		if (flag == 0)
		{
			t = p;
			flag++;
		}
		head2 = head2->next;
	}
	return t;
}
struct node * insert(struct node * first, int n)
{
	struct node *p, *t;
	t = first;
	p = (struct node *)malloc(sizeof(struct node));
	p->num = n;
	p->next = NULL;
	if (first == NULL)
	{
		first = p;
		return first;
	}
	while (t->next != NULL)
		t = t->next;
	t->next = p;
	return first;
}
