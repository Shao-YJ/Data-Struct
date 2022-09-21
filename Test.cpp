#include"Test.h"


//����10������n�����d��������
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

//�Ȳ���n��[1��100]֮������������Ȼ�������Ĳ���˳������������������ż��
//(��һ�����1��������1��ż��)��ֱ����������ż��������Ϊֹ��
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
		cout << "��" << i++ << "��:" << outQueue(sin) << " " << outQueue(dou) << endl;
	}
}