#include"SqStack.h"

SqStack StackInit(void)
{
	SqStack s;
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.StackSize = STACK_INIT_SIZE;
	return s;
}

void StackClear(SqStack s)
{
	s.top = s.base;
	return;
}

void StackDestory(SqStack s)
{
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.StackSize = 0;
	return;
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

int IsStackEmpty(SqStack s)
{
	if (s.top == s.base)
		return 1;
	else
		return 0;
}//然而感觉有时间引用这个函数，还不如直接打s.top == s.base╮(╯▽╰)╭

int StackLength(SqStack s)
{
	return s.top - s.base;
}

void Push(SqStack s, SElemType e)
{
	if (s.top - s.base >= s.StackSize)
		StackIncrease(&s);
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

SElemType ElemGetTop(SqStack s)
{
	SElemType out;
	if (s.top == s.base)
		return -1;
	out = *(s.top - 1);
	return out;
}

