#ifndef _TEST_H
#define _TEST_H

#include"std.h"

//输入10进制数n，输出d进制数。
int _10toN(int e, int n);

//先产生n个[1，100]之间的随机整数，然后按照数的产生顺序依次配对输出奇数和偶数
//(即一次输出1个奇数和1个偶数)，直到奇数或者偶数输出完毕为止。
void twoPair(int n);

//有两个进程同时存在于一个程序中。其中第一个进程在屏幕上连续显示字符“ - ”, 与此同时，
//程序不断检测键盘是否有输入，如果有，就读入用户键入的字符并保存到输入缓冲区中。
//在用户输入时，键入的字符并不立即回显在屏幕上。当用户键入一个逗号(, )时，表示第一个进程结束，
//第二个进程从缓冲区中读取那些已键入的字符并显示在屏幕上。第二个进程结束后，程序又进入第一个进程，
//重新显示字符“ - ”, 同时用户又可以继续键入字符，直到用户输入一个分号(;)键，才结束第一个进程，同时也结束整个程序。
void twoProgress();

//假设迷宫由m行n列构成，有一个入口(1, 1)和一个出口(m，n)。
//试找出一条从入口通往出口的可行路径(如输出可通行路径方格的坐标序列)。
void labyrinth(int m, int n);

//设在表达式中允许包含[]和()两种括号，约定([]())  或[([][])]这类的括号匹配格式是正确的，
//而[(]) 或([()) 或(()]这类的括号匹配格式是不正确的
//括号匹配算法
void bracketMatch();

//算术表达式求值
void arthimetic();

void hanoi(char x, int n, char y, char z);

//背包问题
//设有n个物品，每个物品的重量为wi, i = 1, 2, …, n。试从这n个物品中选取若干个，使其重量之和＝背包的容量T。
void bag();
void bag2();

int treeDepth(string str);

template<class T>
void preOrder(BTree<T> tree) {
	LinkStack<BTree<T>*> tstack;
	BTree<T>* p ;
	tstack.push(tree.lc);
	while (!tstack.isEmpty()) {
		p = tstack.pop();
		p->visit();
		if (p->rc)
			tstack.push(p->rc);
		if (p->lc)
			tstack.push(p->lc);
	}
}

template<class T>
void inOrder(BTree<T> tree) {
	LinkStack<BTree<T>*> tstack;
	BTree<T>* p= tree.lc;
	while (p||!tstack.isEmpty()) {
		if (p) {
			tstack.push(p);
			p = p->lc;
		}
		else {
			p = tstack.pop();
			p->visit();
			p = p->rc;
		}
	}
}

template<class T>
void postOrder(BTree<T> tree) {
	LinkStack<BTree<T>*> lstack;
	LinkStack<BTree<T>*> rstack;
	BTree<T>* p;
	lstack.push(tree.lc);
	while (!lstack.isEmpty()) {
		p = lstack.pop();
		rstack.push(p);
		if (p->lc)
			lstack.push(p->lc);
		if (p->rc)
			lstack.push(p->rc);
	}
	while (!rstack.isEmpty()) {
		p = rstack.pop();
		p->visit();
	}
}

//堆排序
void edgeSort(Edge e[], int n);
#endif // !_TEST_H