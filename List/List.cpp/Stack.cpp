#include"../List.h/Stack.h"

void initStack(Stack& S,int n) {
	S.base = (int*)malloc(n*sizeof(int));
	S.top = S.base;
	S.stacksize = n;
}

void push(Stack& S, int e) {
	if (S.top - S.base > S.stacksize)
	{
		int* new_Stack = (int*)realloc(S.base,2 * S.stacksize * sizeof(int));
		if (!new_Stack)
			return;
		S.base = new_Stack;
	}
	*(S.top++) = e;
}

int pop(Stack& S) {
	if (S.top != S.base)
		return *(--S.top);
	else return NULL;
}

void stackToString(Stack S) {
	int* p = S.base;
	while (p<S.top)
	{
		cout << *(p++) << " ";
	}
	cout << endl;
}

void initLinkStack(LinkStack& L,int Data) {
	L = (LinkStack)malloc(sizeof(SNode));
	if (!L)
		return;
	L->data = Data;
	L->next = NULL;
}

void push(LinkStack& L, int e) {
	LinkStack p;
	initLinkStack(p, e);
	p->next = L->next;
	L->next = p;
}

int pop(LinkStack& L) {
	int n;
	LinkStack p;
	p = L->next;
	n = p->data;
	L->next = p->next;
	free(p);
	return n;
}

void stackToString(LinkStack L) {
	LinkStack p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
