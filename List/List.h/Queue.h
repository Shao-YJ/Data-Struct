#pragma once
#include"../../std.h"

typedef struct Queue {
	int* front;
	int* rear;
	int size;
}Queue;

void initQueue(Queue& Q,int n);

void inQueue(Queue& Q, int e);

int outQueue(Queue& Q);

void queueToString(Queue Q);

bool queueIsEmpty(Queue Q);

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*LinkQueue;

void initQueue(LinkQueue& L,int e=NULL);

void inQueue(LinkQueue& L,int e);
int outQueue(LinkQueue& L);

void queueToString(LinkQueue Q);