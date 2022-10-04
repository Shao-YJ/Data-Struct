#ifndef _TREE_H
#define _TREE_H
#include"../std.h"

template<class T>
class BTree {
public:
	T data;
	BTree<T>* lc;
	BTree<T>* rc;

	BTree() { this->lc = this->rc = NULL; };
	BTree(T e);
	void create(string str, int& k);
	void toString();
	void tostring();
	int depth();
};

template<class T>
inline BTree<T>::BTree(T e){
	this->data = e;
	this->lc = this->rc = NULL;
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
#endif // !_TREE_H