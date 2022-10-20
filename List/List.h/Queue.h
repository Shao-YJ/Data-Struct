#ifndef _QUEUE_H
#define _QUEUE_H
#include"../../std.h"

#define MAXSIZE 10

//typedef struct Queue {
//	int* front;
//	int* rear;
//	int size;
//}Queue;
//
//void initQueue(Queue& Q,int n);
//
//void inQueue(Queue& Q, int e);
//
//int outQueue(Queue& Q);
//
//void queueToString(Queue Q);
//
//bool IsEmpty(Queue Q);

template<typename T>
class Queue
{
public:
	T elem[MAXSIZE];
	int front;
	int rear;
	Queue() {
		front = 0; rear = 0;
	}
	void push(T e);
	T pop();
	void toString();
	bool isEmpty();
	bool isFull();
	T head();
	T top();
};

template<typename T>
T Queue<T>::head() {
	return this->elem[front];
}

template<typename T>
T Queue<T>::top() {
	return this->elem[rear-1];
}

template<typename T>
void Queue<T>::push(T e) {
	this->elem[rear++] = e;
}

template<typename T>
T Queue<T>::pop() {
	if (this->isEmpty())
		cout << "The Queue is empty." << endl;
	T p = this->elem[front];
	front = (front + 1) % MAXSIZE;
	return p;
}

template<typename T>
void Queue<T>::toString() {
	int head = this->front;
	while (head != rear)
	{
		cout << this->elem[head]<<" ";
		head = (head + 1) % MAXSIZE;
	}
	cout << endl;
}

template<typename T>
bool Queue<T>::isEmpty() {
	return this->front == this->rear;
}

template<typename T>
bool Queue<T>::isFull() {
	return (this->rear + 1) % MAXSIZE == this->front;
}

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*LinkQueue;

void initQueue(LinkQueue& L,int e=NULL);

void inQueue(LinkQueue& L,int e);
int outQueue(LinkQueue& L);

void queueToString(LinkQueue Q);

typedef struct Squeue {
	int elem[MAXSIZE] = {};
	int front=0;
	int rear=0;
}Squeue;

void inQueue(Squeue &S,int e);
int outQueue(Squeue &S);
void queueToString(Squeue S);
bool IsEmpty(Squeue S);
bool IsFull(Squeue S);
#endif