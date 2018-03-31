#include"SqStack.h"

int main(void)
{
	SqStack s = StackInit();
	SElemType input;
	while (1)
	{
		input = getchar();
		wipe_cache(stdin);
		if (input == '$')
			break;
		Push(s, input);
	}
	StackPrint(s);
	system("pause");
	return 0;
}