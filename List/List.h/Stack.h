#pragma once
#include"../../std.h"

template <typename T>
struct Stack {
	T* base;
	T* top;
	int stacksize;
};

//ÏßÐÔÕ»²Ù×÷
template<typename T>
void initStack(Stack<T>& S, int n)
{
	S.base = (T*)malloc(n * sizeof(T));
	S.top = S.base;
	S.stacksize = n;
}

template <typename T>
void push(Stack<T>& S, int e) {
	if (S.top - S.base > S.stacksize)
	{
		int* new_Stack = (T*)realloc(S.base, 2 * S.stacksize * sizeof(T));
		if (!new_Stack)
			return;
		S.base = new_Stack;
	}
	*(S.top++) = e;
}

template <typename T>
int pop(Stack<T>& S) {
	if (S.top != S.base)
		return *(--S.top);
	else return NULL;
}

template <typename T>
bool stackIsEmpty(Stack<T> S) {
	return S.top == S.base;
}

template <typename T>
void stackToString(Stack<T> S) {
	T* p = S.base;
	while (p < S.top)
	{
		cout << *(p++) << " ";
	}
	cout << endl;
}

//Á´Õ»²Ù×÷
template <typename T>
class SNode {
public:
	SNode(T Data=NULL);
	T data;
	SNode<T>* next;
};

template <typename T>
class LinkStack {
public:
	LinkStack(){};
	LinkStack(int size,T Data);
	void m_push(int e);
private:
	SNode<T> head;
	int stacksize;
};

//Á´Õ»²Ù×÷
template<class T>
SNode<T>::SNode(T Data) {
	this->next = NULL;
	this->data = Data;
}

template<class T>
LinkStack<T>::LinkStack(int size, T Data) {
	SNode<T> p(Data);
	this->stacksize = size;
}

template<typename T>
void LinkStack<T>::m_push(int e)
{
	SNode<T>* p = new SNode<T>;
	p->data = e;
	p->next = this->head.next;
	this->head.next = p;
}



//
//template <typename T>
//void push(*SNode<T>& L, T e);
//
//template <typename T>
//T pop(*SNode<T>& L);
//
//template <typename T>
//void stackToString(*SNode<T> L);