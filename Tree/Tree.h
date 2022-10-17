#ifndef _TREE_H
#define _TREE_H
#include"../std.h"

template<class T>
class BTree {
public:
	T data;
	BTree<T>* lc;
	BTree<T>* rc;
	int ltag,rtag;//0:分支结点，1：叶子结点

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
	if (!this)return;//是空子树则返回
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

	//处理根节点
	//1.如果当前子树的根节点的左子树为空 就把left指针指向前驱
	if (B->lc == NULL) {
		B->lc = pre;
		B->ltag = 1;
	}
	//如果当前子树的根结点的前驱的右子树为空 就把前驱的right指针指向根节点
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

	if (!B->lc) {		//没有左孩子
		B->ltag = 1;	//修改左标志域
		B->lc = pre;	//左孩子指向前驱结点
	}

	if (!pre->rc) {		//没有右孩子
		pre->rtag = 1;	//修改右标志域
		pre->rc = B;	//前驱结点右孩子指向当前节点
	}
	pre = B;			//保证pre指向下一节点的前驱
	
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

//树的双亲表示法
template<class T>
class TNode {
public:
	T data;  //数据元素
	int parent;//双亲位置
}; //结点结构

//树的存储结构
template<class T>
class PTree {
public:
	int length;
	TNode<T> tree[100];
	int nodenum;//结点数

	PTree();
};

template<class T>
PTree<T>::PTree() {
	this->length = 100;
	this->nodenum = 0;
}

//树的孩子表示法
template<class T>
class CNode {
public:
	int child; // 孩子结点在顺序表中的位置
	CNode<T>* next;
};//孩子链表结构

template<class T>
class Tchild{
public:
	T data;
	CNode<T>  firstchild;//孩子链表头指针

	Tchild(T e) {
		this->data = e;
		this->firstchild = new CNode<T>;
	}
	~Tchild() {
		delete this->firstchild;
	}
};//表头指针结构

template<class T>
class CTree{
public:
	Tchild<T>  T[100];
	int  r, n;//根的位置，结点数

	CTree() { r = 0; n = 0; }
};//树的存储结构

//树的孩子兄弟表示法
template<class T>
class CSnode{
public:
	T data;//数据元素域
	CSnode* Child1;//第1个孩子
	CSnode* Sibling;//下1个兄弟

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

//树的先根遍历
template<class T>
void CSnode<T>::preTree(){
	if (!this)return;
	cout << this->data;
	preTree(this->Child1);
	preTree(this->Sibling);
}

//树的后根遍历
template<class T>
void CSnode<T>::postTree() {
	if (!this)return;
	preTree(this->Child1);
	preTree(this->Sibling);
	cout << this->data;
}

//树的层序遍历
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