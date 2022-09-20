#pragma once
#include"std.h"

typedef struct Stack {
	int* base;
	int* top;
	int stacksize;
}Stack;

void initStack(Stack& S,int n);
int pop(Stack& S);
void push(Stack& S,int e);
void stackToString(Stack S);

typedef struct SNode {
	int data;
	struct SNode* next;
}SNode,*LinkStack;

void initLinkStack(LinkStack& L,int Data=NULL);
void push(LinkStack& L, int e);
int pop(LinkStack& L);
void stackToString(LinkStack L);