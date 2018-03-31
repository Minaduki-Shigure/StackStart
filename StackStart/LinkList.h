#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LNode *NewNode(void);
LNode *ListInit(int length);
int ListLength(LNode *ListHead);
void ElemInsert(LNode *ListHead, int location, ElemType input);
ElemType ElemDelete(LNode *ListHead, int location);
void ListPrint(LNode *ListHead);
LNode *FindFirstCommonNode(LNode *head1, LNode *head2);
void ListInvert(LNode *head);