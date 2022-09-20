#pragma once
#include"std.h"

typedef struct Queue {
	int* front;
	int* rear;
	int size;
}Queue;

void initQueue(Queue& Q,int n);

void inQueue(Queue& Q, int e);

int outQueue(Queue& Q);

void queueToString(Queue Q);