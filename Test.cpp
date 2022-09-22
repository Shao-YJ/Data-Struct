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
		cout << "第" << i++ << "组:" << outQueue(sin) << " " << outQueue(dou) << endl;
	}
}

//有两个进程同时存在于一个程序中。其中第一个进程在屏幕上连续显示字符“ - ”, 与此同时，
//程序不断检测键盘是否有输入，如果有，就读入用户键入的字符并保存到输入缓冲区中。
//在用户输入时，键入的字符并不立即回显在屏幕上。当用户键入一个逗号(, )时，表示第一个进程结束，
//第二个进程从缓冲区中读取那些已键入的字符并显示在屏幕上。第二个进程结束后，程序又进入第一个进程，
//重新显示字符“ - ”, 同时用户又可以继续键入字符，直到用户输入一个分号(;)键，才结束第一个进程，同时也结束整个程序。
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