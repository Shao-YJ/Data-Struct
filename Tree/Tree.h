#ifndef _TREE_H
#define _TREE_H
#include"../std.h"

template<class T>
class BTree {
public:
	T data;
	BTree<T>* lc;
	BTree<T>* rc;
	int ltag,rtag;//0:��֧��㣬1��Ҷ�ӽ��

	BTree() { this->ltag = 0; this->lc = this->rc = NULL; };
	BTree(T e);
	void create(string str, int& k);
	void toString();
	void tostring();
	int depth();
	void preOrder();
	void inOrder();
	void postOrder();
	void visit();

	static void preThreading(BTree<T>* B, BTree<T>*& pre);
	static void inThreading(BTree<T>* B, BTree<T>* &pre);
	static void postThreading(BTree<T>* B, BTree<T>*& pre);
	static void preOrderTraverse(BTree<T>* B);
	static void inOrderTraverse(BTree<T>* B);
	static void postOrderTraverse(BTree<T>* B);
};

template<class T>
inline BTree<T>::BTree(T e){
	this->data = e;
	this->ltag = 0;
	this->rtag = 0;
	this->lc = this->rc = NULL;
}

template<class T>
inline void BTree<T>::visit() {
	cout << this->data;
}

template<class T>
void BTree<T>::create(string str,int &k)
{
	T ch = str[k];
	while (ch) {
		if (ch == '('&&str[k+1]==',')k+=2;
		else if (ch == '(' || ch == ',' && str[k + 1] == ')')k++;
		else if (ch == ')' || ch == ',') {
			k++; return;
		}
		//if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
		else{
			BTree<T>* t = (BTree<T>*)malloc(sizeof(BTree<T>));
			t->rtag = t->ltag = 0;
			t->lc = t->rc = NULL;
			t->data = ch;
			if (k != 0 && str[k - 1] == ',')this->rc = t;
			else this->lc = t;
			k++;
			t->create(str, k);
			ch = str[k];
			continue;
		}
		ch = str[k];
	}
}

template<class T>
void BTree<T>::toString() {
	this->lc->tostring();
	cout << endl;
}

template<class T>
void BTree<T>::tostring() {
	if (!this)return;//�ǿ������򷵻�
	cout << this->data ;
	if (this->lc) {
		cout << "(";
		this->lc->tostring();
	}
	else {
		if (this->rc)
			cout << "(";
		else return;
	}
	if (this->rc) {
		cout << ",";
		this->rc->tostring();
		cout << ")";
	}
	else if(!this->rc){
		cout <<")"; return;
	}
}

template<class T>
int BTree<T>::depth() {
	if (!this)return -1;
	int ld = this->lc->depth();
	int rd = this->rc->depth();
	return ld > rd ? ld + 1 : rd + 1;
}

template<class T>
void BTree<T>::preOrder() {
	if (!this)return;
	cout << this->data;
	this->lc->preOrder();
	this->rc->preOrder();
}

template<class T>
void BTree<T>::inOrder() {
	if (!this)return;
	this->lc->inOrder();
	cout << this->data;
	this->rc->inOrder();
}

template<class T>
void BTree<T>::postOrder() {
	if (!this)return;
	this->lc->postOrder();
	this->rc->postOrder();
	cout << this->data;
}

template<class T>
void BTree<T>::preThreading(BTree<T>* B,BTree<T>* &pre) {
	if (!B || !pre)return;

	//������ڵ�
	//1.�����ǰ�����ĸ��ڵ��������Ϊ�� �Ͱ�leftָ��ָ��ǰ��
	if (B->lc == NULL) {
		B->lc = pre;
		B->ltag = 1;
	}
	//�����ǰ�����ĸ�����ǰ����������Ϊ�� �Ͱ�ǰ����rightָ��ָ����ڵ�
	if (pre != NULL && pre->rc == NULL) {
		pre->rc = B;
		pre->rtag = 1;
	}

	pre = B;
	if (B->ltag == 0)
		preThreading(B->lc, pre);
	if (B->rtag == 0)
		preThreading(B->rc, pre);
	return;
}

template<class T>
void BTree<T>::preOrderTraverse(BTree<T>* B) {
	if (!B)	return;
	BTree<T>* p = B;
	while (p) {
		while (p->ltag == 0) {
			p->visit();
			p = p->lc;
		}
		p->visit();
		p = p->rc;
	}
	cout << endl;
}

template<class T>
void BTree<T>::inThreading(BTree<T>* B,BTree<T>* &pre)
{
	if (!B)return;
	inThreading(B->lc, pre);

	if (!B->lc) {		//û������
		B->ltag = 1;	//�޸����־��
		B->lc = pre;	//����ָ��ǰ�����
	}

	if (!pre->rc) {		//û���Һ���
		pre->rtag = 1;	//�޸��ұ�־��
		pre->rc = B;	//ǰ������Һ���ָ��ǰ�ڵ�
	}
	pre = B;			//��֤preָ����һ�ڵ��ǰ��
	
	inThreading(B->rc, pre);
}

template<class T>
void BTree<T>::inOrderTraverse(BTree<T>* B) {
	BTree<T>* p = B;
	while (p) {
		while (p->ltag == 0)p = p->lc;
		p->visit();
		while (p->rtag == 1) {
			p = p->rc;
			p->visit();
		}
		p = p->rc;
	}
}

template<class T>
void BTree<T>::postThreading(BTree<T>* B, BTree<T>*& pre) {
	if (!B)return;

	postThreading(B->lc, pre);
	postThreading(B->rc, pre);

	if (!B->lc) {
		B->ltag = 1;
		B->lc = pre;
	}
	if (pre && !pre->rc) {
		pre->rtag = 1;
		pre->rc = B;
	}
	pre = B;
}

template<class T>
void BTree<T>::postOrderTraverse(BTree<T>* B) {
	if (!B)return;
	LinkStack<char> stack;
	BTree<T>* p = B;
	stack.push(p->data);
	while (p) {
		while (p->rtag == 0&&p->rc) {
			p = p->rc;
			stack.push(p->data);
		}
		while (p->lc&& p->ltag == 1) {
			p = p->lc;
			stack.push(p->data);
		}
		if (p->rc&&p->lc)
			continue;
		p = p->lc;
	}
	cout << endl;
	while (!stack.isEmpty()) {
		cout << stack.pop();
	}
}

//����˫�ױ�ʾ��
template<class T>
class TNode {
public:
	T data;  //����Ԫ��
	int parent;//˫��λ��
}; //���ṹ

//���Ĵ洢�ṹ
template<class T>
class PTree {
public:
	int length;
	TNode<T> tree[100];
	int nodenum;//�����

	PTree();
};

template<class T>
PTree<T>::PTree() {
	this->length = 100;
	this->nodenum = 0;
}

//���ĺ��ӱ�ʾ��
template<class T>
class CNode {
public:
	int child; // ���ӽ����˳����е�λ��
	CNode<T>* next;
};//��������ṹ

template<class T>
class Tchild{
public:
	T data;
	CNode<T>  firstchild;//��������ͷָ��

	Tchild(T e) {
		this->data = e;
		this->firstchild = new CNode<T>;
	}
	~Tchild() {
		delete this->firstchild;
	}
};//��ͷָ��ṹ

template<class T>
class CTree{
public:
	Tchild<T>  T[100];
	int  r, n;//����λ�ã������

	CTree() { r = 0; n = 0; }
};//���Ĵ洢�ṹ

//���ĺ����ֵܱ�ʾ��
template<class T>
class CSnode{
public:
	T data;//����Ԫ����
	CSnode* Child1;//��1������
	CSnode* Sibling;//��1���ֵ�

	CSnode(T e);
	void preTree();
	void postTree();
	static void levelTree(CSnode<T> &head);
	void visit() { cout << this->data; }
};

template<class T>
CSnode<T>::CSnode(T e) {
	this->data = e;
	this->Child1 = NULL;
	this->Sibling = NULL;
}

//�����ȸ�����
template<class T>
void CSnode<T>::preTree(){
	if (!this)return;
	cout << this->data;
	preTree(this->Child1);
	preTree(this->Sibling);
}

//���ĺ������
template<class T>
void CSnode<T>::postTree() {
	if (!this)return;
	preTree(this->Child1);
	preTree(this->Sibling);
	cout << this->data;
}

//���Ĳ������
template<class T>
void CSnode<T>::levelTree(CSnode<T> &head) {
	CSnode<T>* p = &head;
	queue<CSnode<T>*> tqueue;
	//tqueue.push(p);
	while (p||!tqueue.empty()) {
		if (!p && !tqueue.empty()) { 
			p = tqueue.front(); tqueue.pop(); }
		p->visit();
		cout << " ";
		if (p->Child1)tqueue.push(p->Child1);
		p = p->Sibling;
	}
}
#endif // !_TREE_H