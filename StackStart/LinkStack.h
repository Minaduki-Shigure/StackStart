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

LinkStackNode *NewNode(void);
LinkStack LinkStackInit(void);
void LinkStackDestroy(LinkStack s);
void LinkPush(LinkStack s, SElemType e);