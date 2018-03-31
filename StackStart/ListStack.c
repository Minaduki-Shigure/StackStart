#include"LinkStack.h"

void wipe_cache(FILE *fp)
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

LinkStackNode *NewNode(void)
{
	LinkStackNode *p = NULL;
	p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	p->next = NULL;
	return p;
}

LinkStack LinkStackInit(void)
{
	LinkStackNode *head = NULL, *p = NULL, *p1 = NULL;
	LinkStack s;
	int i = 0;
	for (i = 0; i <= STACK_INIT_SIZE; i++)
	{
		p = NewNode();
		p->data = i;
		p->next = NULL;
		if (i == 0)
			head = p1 = p;
		else
		{
			p1->next = p;
			p1 = p;
		}
	}
	s.base = head;
	s.top = s.base;
	s.StackSize = STACK_INIT_SIZE;
	return s;
}

void LinkStackDestroy(LinkStack s)
{
	LinkStackNode *head = NULL, *p = NULL, *p1 = NULL;
	head = s.base;
	p = head;
	while (1)
	{
		p1 = p->next;
		free(p);
		if (p1 == NULL)
			break;
	}
	s.base = s.top = NULL;
	s.StackSize = 0;
	return;
}

void LinkPush(LinkStack *s, SElemType e)
{
	if ((*s).top == NULL)
		(*s).top = NewNode();
	(*s).top->data = e;
	(*s).top = (*s).top->next;
	return;
}

SElemType LinkPop(LinkStack *s)
{
	SElemType out;
	LinkStackNode *top = (*s).top, *head = (*s).base, *p = NULL, *p1 = NULL;
	if (top == NULL)
		return -1;
	p = head;
	while (1)
	{
		p1 = p->next;
		if (p1->next == NULL)
			break;
		p = p1;
	}
	out = p1->data;
	p->next = NULL;
	free(p1);
	(*s).top = p;
	return out;
}

void StackPrint(LinkStack *s)
{
	LinkStackNode *out = (*s).base;
	printf("\n");
	while (1)
	{
		if (out == (*s).top)
			break;
		printf("%c\n", out->data);
		out = out->next;
	}
	printf("\nEOF\n");
	return;
}