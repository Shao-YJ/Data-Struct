#include"std.h"

void stackTest();
void queueTest();

int main() {

	queueTest();
	

	return 0;
}

void queueTest() {
	Queue q1;

	initQueue(q1, 10);
	for (int i = 0; i < 10; i++) 
		inQueue(q1, i);
	queueToString(q1);
	
	inQueue(q1, 11);
	queueToString(q1);

	//int n = outQueue;
	cout << outQueue(q1)<<endl;
	queueToString(q1);
}

void stackTest() {
	Stack s1;

	initStack(s1,5);

	for (int i = 0; i < 5; i++)
		push(s1, i);
	stackToString(s1);
	int n=pop(s1);
	cout << n << endl;
	stackToString(s1);

	LinkStack s2;
	initLinkStack(s2);
	for (int i = 0; i < 5; i++)
		push(s2, i*2);
	stackToString(s2);
	n = pop(s2);
	cout << n << endl;
	stackToString(s2);


}


