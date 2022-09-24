#include"Test.h"

int _10toN(int e, int n) {
	int p = 0;
	Stack<int> s;
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

void twoPair(int n) {
	int i = 0;
	int p;
	Queue sin, dou;
	initQueue(sin,100);
	initQueue(dou, 100);
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		p = rand() % 100 + 1;
		if (p % 2)
			inQueue(sin, p);
		else
			inQueue(dou, p);
	}
	i = 1;
	while (!IsEmpty(sin) && !IsEmpty(dou)) {
		cout << "ตฺ" << i++ << "ื้:" << outQueue(sin) << " " << outQueue(dou) << endl;
	}
}

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

void labyrinth(int m,int n) {
	typedef struct Site {
		int x;
		int y;
		int next;
	public:
		Site(int i, int j) {
			x = i; y = j; next = 2;
		}
		Site(){}
	}Site;

	int i, j;

	int Map[10][10] = { 0 };
	for (i = 1; i < 9; i++)
		for (j = 1; j < 9; j++)
			Map[i][j] = 1;

	Map[1][3] = 0;	Map[1][4] = 0;	Map[1][6] = 0;	Map[2][6] = 0;	Map[3][1] = 0;
	Map[3][2] = 0;	Map[3][5] = 0;	Map[4][4] = 0;	Map[5][3] = 0;	Map[5][6] = 0;
	Map[5][8] = 0;	Map[6][3] = 0;	Map[6][6] = 0;	Map[7][5] = 0;	Map[7][6] = 0;
	Map[8][7] = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			cout << Map[i][j] << " ";
		cout << endl;
	}

	LinkStack<Site>  link;
	i = 1, j = 1;
	int k,time=0;
	Site s(1, 1),temp;
	link.push(Site(1,1));
	while (i + j) {
		k = 0;
		if (i == m && j == n)k = 9;
		else if (Map[i][j + 1]==1)k = 2;
		else if (Map[i+1][j] == 1)k = 3;
		else if (Map[i][j - 1] == 1)k = 4;
		else if (Map[i-1][j] == 1)k = 5;
		else if (i==1&&j==1)k = 6;

		switch (k) {
		case 0:
			Map[i][j] = -1;
			temp = link.pop(); i = temp.x; j = temp.y;  break;
		case 2:link.push(Site(i, ++j)); Map[i][j] = 2; break;
		case 3:link.push(Site(++i, j)); Map[i][j] = 2; break;
		case 4:link.push(Site(i, --j)); Map[i][j] = 2; break;
		case 5:link.push(Site(--i, j)); Map[i][j] = 2; break;
		case 6:cout << "Search Failed" << endl; return;
		case 9:cout << "Successful Serach,The Route is:" << endl; i = 0; j = 0; break;
		}
	}
	while (link.isEmpty()) {
		temp = link.pop();
		cout << "(" << temp.x << "," << temp.y << ")<--";
	}

}
