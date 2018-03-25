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

SqStack* StackInit(void);