#include"Stack.h"

SqStack* StackInit(void)
{
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.StackSize = STACK_INIT_SIZE;
	return s.base;
}

