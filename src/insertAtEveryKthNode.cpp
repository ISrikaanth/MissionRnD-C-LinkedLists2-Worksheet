/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * insertAtEveryKthNode(struct node *head, int K);
struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if ((head == NULL) || (K <= 0))
		return NULL;
	struct node *t, *n;
	int count = 0, temp = 1, temp1 = 1, count1 = 0;
	t = head;
	while (t != NULL)
	{
		count++;
		t = t->next;
	}
	if (count < K)
		return head;
	t = head;
	while (t != NULL)
	{
		if ((temp == K*temp1 + count1) && (t != NULL))
		{
			n = (struct node *)malloc(sizeof(struct node));
			n->num = K;
			n->next = t->next;
			t->next = n;
			temp1++;
			count1++;
		}
		t = t->next;
		temp++;
	}
	return head;
}
