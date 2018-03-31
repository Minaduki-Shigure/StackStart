#include"LinkStack.h"
#include"LinkList.h"

void InvertTemp(LNode *head);

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
		else if (input == GetTopElem(&s))
			LinkPop(&s);
		else
			LinkPush(&s, input);
	}
	StackPrint(&s);
	system("pause");
	printf("\n");
	LNode *head = ListInit(100);
	printf("Invert initializing!\n");
	ListPrint(head);
	InvertTemp(head);
	printf("\nInvert completed!\n");
	ListPrint(head);
	system("pause");
	return 0;
}

void InvertTemp(LNode *head)
{
	LNode *p = head;
	LNode *p1 = head;
	LinkStack s = LinkStackInit();
	while (1)
	{
		p = p->next;
		if (p == NULL)
			break;
		LinkPush(&s, (SElemType)p->data);
	}
	while (1)
	{
		p1 = p1->next;
		if (s.top == s.base)
			break;
		p1->data = LinkPop(&s);
	}
	return;
}