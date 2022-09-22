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
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		p = rand() % 100 + 1;
		if (p % 2)
			inQueue(sin, p);
		else
			inQueue(dou, p);
	}
	i = 1;
	while (!IsEmpty(sin) && !IsEmpty(dou)) {
		cout << "��" << i++ << "��:" << outQueue(sin) << " " << outQueue(dou) << endl;
	}
}

//����������ͬʱ������һ�������С����е�һ����������Ļ��������ʾ�ַ��� - ��, ���ͬʱ��
//���򲻶ϼ������Ƿ������룬����У��Ͷ����û�������ַ������浽���뻺�����С�
//���û�����ʱ��������ַ�����������������Ļ�ϡ����û�����һ������(, )ʱ����ʾ��һ�����̽�����
//�ڶ������̴ӻ������ж�ȡ��Щ�Ѽ�����ַ�����ʾ����Ļ�ϡ��ڶ������̽����󣬳����ֽ����һ�����̣�
//������ʾ�ַ��� - ��, ͬʱ�û��ֿ��Լ��������ַ���ֱ���û�����һ���ֺ�(;)�����Ž�����һ�����̣�ͬʱҲ������������
void twoProgress() {
	char ch;
	Squeue s;
	while (true) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == *",") {
				while (!IsEmpty(s)) {
					cout << (char)outQueue(s);
				}
				continue;
			}
			inQueue(s, ch);
			if (ch == *";")
				break;
		}
		Sleep(100);
		cout << "-";
	}
}