#include"../List.h/Queue.h"

void initQueue(Queue& Q,int n) {
	Q.front = (int*)malloc(n * sizeof(int));
	Q.rear = Q.front;
	Q.size = n;
}

void inQueue(Queue& Q, int e) {
	if (Q.rear - Q.front == Q.size) {
		int* temp = (int*)realloc(Q.front, 2 * Q.size * sizeof(int));
		if (!temp)
			return;
		Q.front = temp;
		Q.rear = Q.front + Q.size;
		Q.size += Q.size;
	}
	*(Q.rear++) = e;
}

int outQueue(Queue& Q) {
	if (Q.rear != Q.front)
		return *Q.front++;
	return NULL;
}

void queueToString(Queue Q) {
	int *p = Q.front, *q = Q.rear;
	while (p < q) {
		cout << *p++ << " ";
	}
	cout << endl;
}

bool IsEmpty(Queue Q) {
	return Q.front == Q.rear;
}

void initQueue(LinkQueue &L,int e) {
	L = (LinkQueue)malloc(sizeof(QNode));
	if (!L)
		return;
	L->data = e;
	L->next = NULL;
}

void inQueue(LinkQueue& L,int e) {
	LinkQueue p = L,t;
	while (p->next)
		p = p->next;
	initQueue(t, e);
	p->next = t;
}

int outQueue(LinkQueue& L) {
	LinkQueue p = L->next;
	int n = p->data;
	L->next = p->next;
	free(p);
	return n;
}

void queueToString(LinkQueue L) {
	LinkQueue p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void inQueue(Squeue &S,int e) {
	if (IsFull(S)) {
		cout << "Queue is full!" << endl;
		return;
	}
	S.elem[S.rear] = e;
	S.rear = (S.rear + 1) % MAXSIZE;
}

int outQueue(Squeue& S) {
	if (IsEmpty(S))
		return NULL;
	int n = S.elem[S.front];
	S.front = (S.front + 1) % MAXSIZE;
	return n;
}

void queueToString(Squeue S) {
	int front = S.front;
	int rear = S.rear;
	while (front != rear) {
		cout << S.elem[front] << " ";
		front = (front + 1) % MAXSIZE;
	}
	cout << endl;
}

bool IsEmpty(Squeue S) {
	return S.rear == S.front;
}

bool IsFull(Squeue S) {
	return (S.rear + 1) % MAXSIZE == S.front;
}