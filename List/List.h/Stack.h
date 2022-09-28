#ifndef _STACK_H
#define _STACK_H
#include"../../std.h"

template <typename T>
struct Stack {
	T* base;
	T* top;
	int stacksize;
};

//线性栈操作
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



//------链栈操作------
template <typename T>
class SNode {
public:
	SNode();
	SNode(T Data);
	T data;
	SNode<T>* next;
};

template <typename T>
class LinkStack {
public:
	LinkStack();
	void push(T e);
	T pop();
	T top();
	void toString();
	bool isEmpty();
private:
	SNode<T> head;
};

template<class T>
T LinkStack<T>::top() {
	if (isEmpty())
		return this->head.data;
	return this->head.next->data;
}

template<class T>
SNode<T>::SNode() {
	this->next = NULL;
}

template<class T>
SNode<T>::SNode(T Data) {
	this->next = NULL;
	this->data = Data;
}

template<class T>
LinkStack<T>::LinkStack() {
	SNode<T> p;
	this->head = p;
}

template<typename T>
void LinkStack<T>::push(T e){
	SNode<T>* p = new SNode<T>(e);
	p->data = e;
	p->next = this->head.next;
	this->head.next = p;
}

template<typename T>
T LinkStack<T>::pop() {
	if (this->isEmpty())
	{
		cout << "The stakc is empty.";
		return this->head.data;
	}
	SNode<T>* p = this->head.next;
	this->head.next = p->next;
	T data = p->data;
	free(p);
	return data;
}

template<typename T>
void LinkStack<T>::toString() {
	SNode<T>* p = this->head.next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<typename T>
bool LinkStack<T>::isEmpty() {
	if (this->head.next)
		return false;
	else
		return true;
}
#endif