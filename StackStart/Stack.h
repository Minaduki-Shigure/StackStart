#pragma once

#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCRESEMENT 10

typedef int SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int StackSize;
}SqStack;

SqStack StackInit(void);
void StackDestory(SqStack s);
void StackIncrease(SqStack *s);
int IsStackEmpty(SqStack s);
void Push(SqStack s, SElemType e);
SElemType Pop(SqStack s);
SElemType ElemGetTop(SqStack s);