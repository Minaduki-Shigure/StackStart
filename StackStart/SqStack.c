#include"SqStack.h"

SqStack SqStackInit(void)
{
	SqStack s;
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.StackSize = STACK_INIT_SIZE;
	return s;
}

void SqStackClear(SqStack s)
{
	s.top = s.base;
	return;
}

void SqStackDestory(SqStack s)
{
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.StackSize = 0;
	return;
}

void SqStackIncrease(SqStack *s)
{
	(*s).base = (SElemType *)realloc((*s).base, ((*s).StackSize + STACK_INCRESEMENT) * sizeof(SElemType));
	if (!(*s).base)
		exit(-1);
	(*s).top = (*s).base + (*s).StackSize;
	(*s).StackSize += STACK_INCRESEMENT;
	return;
}

int SqIsStackEmpty(SqStack s)
{
	if (s.top == s.base)
		return 1;
	else
		return 0;
}//然而感觉有时间引用这个函数，还不如直接打s.top == s.base╮(╯▽╰)╭

int SqStackLength(SqStack s)
{
	return s.top - s.base;
}

void SqPush(SqStack s, SElemType e)
{
	if (s.top - s.base >= s.StackSize)
		SqStackIncrease(&s);
	*s.top++ = e;
	return;
}

SElemType SqPop(SqStack s)
{
	SElemType out;
	if (s.top == s.base)
		return -1;
	out = *--s.top;
	return out;
}

SElemType SqElemGetTop(SqStack s)
{
	SElemType out;
	if (s.top == s.base)
		return -1;
	out = *(s.top - 1);
	return out;
}