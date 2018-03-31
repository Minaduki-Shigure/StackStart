#pragma once

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCRESEMENT 10

typedef char SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int StackSize;
}SqStack;

void wipe_cache(FILE *fp);
SqStack StackInit(void);
void StackClear(SqStack s);
void StackDestory(SqStack s);
void StackIncrease(SqStack *s);
int IsStackEmpty(SqStack s);
int StackLength(SqStack s);
void Push(SqStack s, SElemType e);
SElemType Pop(SqStack s);
SElemType ElemGetTop(SqStack s);
void StackPrint(SqStack s);