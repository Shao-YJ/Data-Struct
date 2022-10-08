#ifndef _TEST_H
#define _TEST_H

#include"std.h"

//����10������n�����d��������
int _10toN(int e, int n);

//�Ȳ���n��[1��100]֮������������Ȼ�������Ĳ���˳������������������ż��
//(��һ�����1��������1��ż��)��ֱ����������ż��������Ϊֹ��
void twoPair(int n);

//����������ͬʱ������һ�������С����е�һ����������Ļ��������ʾ�ַ��� - ��, ���ͬʱ��
//���򲻶ϼ������Ƿ������룬����У��Ͷ����û�������ַ������浽���뻺�����С�
//���û�����ʱ��������ַ�����������������Ļ�ϡ����û�����һ������(, )ʱ����ʾ��һ�����̽�����
//�ڶ������̴ӻ������ж�ȡ��Щ�Ѽ�����ַ�����ʾ����Ļ�ϡ��ڶ������̽����󣬳����ֽ����һ�����̣�
//������ʾ�ַ��� - ��, ͬʱ�û��ֿ��Լ��������ַ���ֱ���û�����һ���ֺ�(;)�����Ž�����һ�����̣�ͬʱҲ������������
void twoProgress();

//�����Թ���m��n�й��ɣ���һ�����(1, 1)��һ������(m��n)��
//���ҳ�һ�������ͨ�����ڵĿ���·��(�������ͨ��·���������������)��
void labyrinth(int m, int n);

//���ڱ��ʽ���������[]��()�������ţ�Լ��([]())  ��[([][])]���������ƥ���ʽ����ȷ�ģ�
//��[(]) ��([()) ��(()]���������ƥ���ʽ�ǲ���ȷ��
//����ƥ���㷨
void bracketMatch();

//�������ʽ��ֵ
void arthimetic();

void hanoi(char x, int n, char y, char z);

//��������
//����n����Ʒ��ÿ����Ʒ������Ϊwi, i = 1, 2, ��, n���Դ���n����Ʒ��ѡȡ���ɸ���ʹ������֮�ͣ�����������T��
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
#endif // !_TEST_H