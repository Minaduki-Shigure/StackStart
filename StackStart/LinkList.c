#include"LinkList.h"

LNode *NewNode(void)
{
	LNode *p = NULL;
	p = (LNode*)malloc(sizeof(LNode));
	return p;
}

LNode *ListInit(int length)
{
	LNode *head = NULL, *p = NULL, *p1 = NULL;
	int i = 0;
	for (i = 0; i <= length; i++)
	{
		p = NewNode();
		p->data = i;
		p->next = NULL;
		if (i == 0)
			head = p1 = p;
		else
		{
			p1->next = p;
			p1 = p;
		}
	}
	return head;
}

int ListLength(LNode *ListHead)
{
	LNode *p = ListHead;
	int i = 0;
	while (1)
	{
		p = p->next;
		if (p == NULL)
			break;
		i++;
	}
	return i;
}

void ElemInsert(LNode *ListHead, int location, ElemType input)
{
	LNode *p = NewNode();
	LNode *temp = NULL, *temp1 = NULL, *swap = NULL;
	p->data = input;
	int i = 0;
	temp1 = ListHead;
	for (i = 0; i < location - 1; i++)
	{
		temp = temp1->next;
		temp1 = temp;
	}
	swap = temp->next;
	temp->next = p;
	p->next = swap;
	return;
}

ElemType ElemDelete(LNode *ListHead, int location)
{
	LNode *temp = NULL, *temp1 = NULL, *swap = NULL;
	int i = 0;
	ElemType output;
	temp1 = ListHead;
	for (i = 0; i < location - 1; i++)
	{
		temp = temp1->next;
		temp1 = temp;
	}
	temp = temp1->next;
	swap = temp->next;
	output = temp->data;
	free(temp);
	temp1->next = swap;
	return output;
}

void ListPrint(LNode *ListHead)
{
	LNode *p = ListHead;
	ElemType out;
	while (1)
	{
		p = p->next;
		if (p == NULL)
			break;
		out = p->data;
		printf("%3d\t", out);
	}
	printf("\n");
	return;
}

LNode *FindFirstCommonNode(LNode *head1, LNode *head2)
{
	int length1 = 0, length2 = 0, temp = 0;
	int i = 0;
	LNode *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
	length1 = ListLength(head1);
	length2 = ListLength(head2);
	temp = length1 - length2;
	if (temp >= 0)
	{
		p1 = head1;
		p2 = head2;
	}
	else
	{
		p1 = head2;
		p2 = head1;
		temp = -temp;
	}
	p3 = p1;
	p4 = p2;
	for (i = 0; i < temp; i++)
		p3 = p3->next;
	while (1)
	{
		if (p3 == p4)
			break;
		p3 = p3->next;
		p4 = p4->next;
		if (p3 == NULL || p4 == NULL)
			return NULL;
	}
	return p3;
}

void ListInvert(LNode *head)
{
	if (head->next == NULL)
		return;
	LNode *p = NULL, *p1 = NULL;
	p = head->next;
	head->next = NULL;
	while (p)
	{
		p1 = p;
		p = p->next;
		p1->next = head->next;
		head->next = p1;
	}
	return;
}