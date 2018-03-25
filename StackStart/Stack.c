#include"Stack.h"

SqStack* StackInit(void)
{
	SqStack s;
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.StackSize = STACK_INIT_SIZE;
	return s.base;
}

void StackDestory(SqStack s)
{
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.StackSize = 0;
	return 0;
}

void StackIncrease(SqStack *s)
{
	(*s).base = (SElemType *)realloc((*s).base, ((*s).StackSize + STACK_INCRESEMENT) * sizeof(SElemType));
	if (!(*s).base)
		exit(-1);
	(*s).top = (*s).base + (*s).StackSize;
	(*s).StackSize += STACK_INCRESEMENT;
	return;
}

void Push(SqStack s, SElemType e)
{
	if (s.top - s.base >= s.StackSize)
		StacIncrease(s);
	*s.top++ = e;
	return;
}

SElemType Pop(SqStack s)
{
	SElemType out;
	if (s.top == s.base)
		return -1;
	out = *--s.top;
	return out;
}