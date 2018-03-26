#pragma once

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCRESEMENT 10

typedef int SElemType;

typedef struct SqStack{
	SElemType *base;
	SElemType *top;
	int StackSize;
}SqStack;

SqStack SqStackInit(void);
void SqStackClear(SqStack s);
void SqStackDestory(SqStack s);
void SqStackIncrease(SqStack *s);
int SqIsStackEmpty(SqStack s);
int SqStackLength(SqStack s);
void SqPush(SqStack s, SElemType e);
SElemType SqPop(SqStack s);
SElemType SqElemGetTop(SqStack s);