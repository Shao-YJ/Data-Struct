#pragma once
#include"../../std.h"

#define MAXSIZE 100

typedef struct Queue {
	int* front;
	int* rear;
	int size;
}Queue;

void initQueue(Queue& Q,int n);

void inQueue(Queue& Q, int e);

int outQueue(Queue& Q);

void queueToString(Queue Q);

bool IsEmpty(Queue Q);

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