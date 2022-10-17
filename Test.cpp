#include"Test.h"

//输入10进制数n，输出d进制数。
int _10toN(int e, int n) {
	int p = 0;
	MStack<int> s;
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
	Queue<int> sin, dou;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		p = rand() % 100 + 1;
		if (p % 2)
			sin.push(p);
		else
			dou.push(p);
	}
	i = 1;
	while (!sin.isEmpty() && !dou.isEmpty()) {
		cout << "第" << i++ << "组:" << sin.pop() << " " << dou.pop() << endl;
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

//假设迷宫由m行n列构成，有一个入口(1, 1)和一个出口(m，n)。
//试找出一条从入口通往出口的可行路径(如输出可通行路径方格的坐标序列)。
void labyrinth(int m,int n) {
	typedef struct Site {
		int x;
		int y;
	public:
		Site(int i, int j) {
			x = i; y = j; 
		}
		Site() {
			x = 0; y = 0;
		}
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
	int k;
	Site temp;
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
		case 2:link.push(Site(i, j)); Map[i][j++] = -1; break;
		case 3:link.push(Site(i, j)); Map[i++][j] = -1; break;
		case 4:link.push(Site(i, j)); Map[i][j--] = -1; break;
		case 5:link.push(Site(i, j)); Map[i--][j] = -1; break;
		case 6:cout << "Search Failed" << endl; return;
		case 9:link.push(Site(i, j));
			cout << "Successful Serach,The Route is:" << endl; i = 0; j = 0; break;
		}
	}
	temp = link.pop();
	cout << "(" << temp.x << "," << temp.y << ")";
	while (!link.isEmpty()) {
		temp = link.pop();
		cout << "<--(" << temp.x << "," << temp.y << ")";
	}

}

//设在表达式中允许包含[]和()两种括号，约定([]())  或[([][])]这类的括号匹配格式是正确的，
//而[(]) 或([()) 或(()]这类的括号匹配格式是不正确的
//括号匹配算法
void bracketMatch() {
	MList<char> p(100);
	cin >> p;
	p.n = strlen(p.elem);
	LinkStack<char> chstack;
	char ch,temp;
	int i, n = p.n;
	for (i = 0; i < n; i++)
	{
		ch = p.elem[i];
		if (ch == *"[" || ch == *"{"||ch==*"(")
			chstack.push(ch);
		if (ch == *"]" || ch == *"}" || ch == *")")
		{
			temp = chstack.pop();
			switch (temp) {
			case * "[":if (ch == *"]")break;
			case * "{":if (ch == *"}")break;
			case * "(":if (ch == *")")break;
			default:cout << "The expression is invalid." << endl; return;
			}
		}
	}
	if (i == n && !chstack.isEmpty())
	{
		cout << "The expression is invalid." << endl;
		return;
	}
	cout << "The bracket is match!" << endl;
}

//算术表达式求值
void arthimetic() {
	MList<char> list(100);
	LinkStack<char> stack;
	Queue<char> queue;

	cin >> list;
	int n = strlen(list.elem);
	int i = 0;
	char ch,p;
	while (i < n) {
		ch = list.elem[i++];
		if (ch >= 48 && ch <= 57) {
			queue.push(ch);
			continue;
		}
		else if (queue.top() >= 48 && queue.top() <= 57) {
			queue.push(*" ");
		}
		if (ch == *"(") {
			stack.push(ch);
			continue;
		}
		if (ch == *"*" || ch == *"/") {
			if (stack.isEmpty()){
				stack.push(ch);
				continue;
			}
			p = stack.top();
			if (p == *"(" || p == *"+" || p == *"-")
				stack.push(ch);
			else
			{
				queue.push(stack.pop());
				stack.push(ch);
			}
			continue;
		}
		if (ch == *"+" || ch == *"-") {
			if (stack.isEmpty() || stack.top() == *"(")
				stack.push(ch);
			else {
				while (!stack.isEmpty() && stack.top() != *"("){
					queue.push(stack.pop());
				}
				stack.push(ch);
			}
			continue;
		}
		if (ch == *"#"&&i==n) {
			while (!stack.isEmpty())
				queue.push(stack.pop());
			break;
		}
		else if(i==n){
			cout << "The arthimetic is invalid!!!" << endl;
			return;
		}
		while (ch == *")")
		{
			p = stack.pop();
			if (p != *"(")
				queue.push(p);
			else
				break;
		}
	}
	queue.toString();

	LinkStack<int> numStack;
	while (!queue.isEmpty()) {
		i = 0;
		while (queue.head() >= 48 && queue.head() <= 57)
		{
			i = i * 10 + (int)(queue.pop()-48);
		}
		if (i) {
			numStack.push(i);
			continue;
		}
		ch = queue.pop();
		int a = 0, b = 0,c=0;
		switch (ch) {
		case * " ":break;
		case * "+":b = numStack.pop(); a = numStack.pop(); c = a + b; numStack.push(c); break;
		case * "-":b = numStack.pop(); a = numStack.pop(); c = a - b; numStack.push(c); break;
		case * "*":b = numStack.pop(); a = numStack.pop(); c = a * b; numStack.push(c); break;
		case * "/":b = numStack.pop(); a = numStack.pop(); c = a / b; numStack.push(c); break;
		default:cout << "No choice!" << endl; break;
		}
	}
	cout << numStack.pop();
}

void move(char x, int n, char z)
{
	cout << "将" << x << "柱上的第" << n << "块移动到" << z << "柱上" << endl;
}

void hanoi(char x, int n, char y, char z) {
	if (n == 1)
		move(x, n, z);
	else {
		hanoi(x, n - 1, z, y);
		move(x, n, z);
		hanoi(y, n - 1, x, z);
	}
}

//背包问题
//设有n个物品，每个物品的重量为wi, i = 1, 2, …, n。试从这n个物品中选取若干个，使其重量之和＝背包的容量T。
bool Knapsack(int T, int n,int w[]) {
	if (T == 0)return 1;
	if (T < 0 || n < 1)return 0;
	if (Knapsack(T - w[n - 1], n - 1, w)) {
		cout << w[n - 1] << " "; return 1;
	}
	return Knapsack(T, n - 1,w);
}

void bag() {
	int n = 7;
	int w[7] = { 27,24,17,51,28,32,63, };
	int T = 100;
	Knapsack(T, n, w);
}

bool Knapsack2(int T, int i, int n, int w[]) {
	if (T == 0)
		return 1;
	if (T < 0 || i >= n)return 0;
	if (Knapsack2(T - w[i], i + 1, n, w)) {
		cout << w[i] << " ";
		return 1;
	}
	return Knapsack2(T,i+1,n,w);
}

void bag2() {
	int n = 7;
	int w[7] = { 27,24,17,51,28,32,63, };
	int T = 100;
	Knapsack2(T, 0, n, w);
}


int treeDepth(string str) {
	int k = 0, i = 0,j=0;
	char ch = str[k];
	while (ch) {
		if (ch == '(') {
			i++; if (i > j)j = i;
		}
		if (ch == ')')i--;
		k++; ch = str[k];
	}
	return j+1;
}