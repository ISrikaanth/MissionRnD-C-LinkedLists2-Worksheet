/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head==NULL)
	   return -1;
	struct node *t;
	int count = 0,m,flag=0;
	t = head;
	while (t != NULL)
	{
		count++;
		t = t->next;
	}
	if ((count) % 2 != 0)
	{
		m = count / 2;
		flag = 1;
	}
	else
		m = (count / 2) - 1;
	count = 0;
	while (head != NULL)
	{
		if ((count == m) && (flag == 1))
			return head->num;
		else if ((flag == 0) && (count==m))
			return ((head->num) + (head->next->num)) / 2;
		head=head->next;
		count++;
	}

}
