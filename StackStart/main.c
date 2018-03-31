#include"SqStack.h"
#include"LinkStack.h"

int main(void)
{
	LinkStack s = LinkStackInit();
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