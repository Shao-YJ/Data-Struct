#include"Test.h"


//输入10进制数n，输出d进制数。
int _10toN(int e, int n) {
	int p = 0;
	Stack s;
	initStack(s, 10);

	while (e) {
		push(s, e % n);
		e /= n;
	}
	while (!stackIsEmpty(s)) {
		p = p * 10 + pop(s);
	}
	return p;
}

//先产生n个[1，100]之间的随机整数，然后按照数的产生顺序依次配对输出奇数和偶数
//(即一次输出1个奇数和1个偶数)，直到奇数或者偶数输出完毕为止。
void twoPair(int n) {
	int i = 0;
	int p;
	Queue sin, dou;
	initQueue(sin,100);
	initQueue(dou, 100);

	for (i = 0; i < n; i++) {
		srand(i);
		p = rand() % 100 + 1;
		if (p % 2)
			inQueue(sin, p);
		else
			inQueue(dou, p);
	}
	i = 1;
	while (!queueIsEmpty(sin) && !queueIsEmpty(dou)) {
		cout << "第" << i++ << "组:" << outQueue(sin) << " " << outQueue(dou) << endl;
	}
}