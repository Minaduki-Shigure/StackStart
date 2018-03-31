#pragma once

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100

typedef char SElemType;

typedef struct LinkStackNode{
	SElemType data;
	struct LinkStackNode *next;
}LinkStackNode;

typedef struct LinkStack{
	struct LinkStackNode *base;
	struct LinkStackNode *top;
	int StackSize;
}LinkStack;

void wipe_cache(FILE *fp);
LinkStackNode *NewNode(void);
LinkStack LinkStackInit(void);
void LinkStackDestroy(LinkStack s);
void LinkPush(LinkStack *s, SElemType e);
SElemType LinkPop(LinkStack *s);
void StackPrint(LinkStack *s);
LinkStackNode *GetTopAddress(LinkStack *s);
SElemType GetTopElem(LinkStack *s);