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
	void create(string str,int &k);
	void toString();
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
	if (!this)return;//是空子树则返回
	cout << this->data << " ";
	if (this->lc) {
		cout << "(";
		this->lc->toString();
	}
	else {
		if (this->rc)
			cout << "(";
		else return;
	}
	if (this->rc) {
		cout << ",";
		this->rc->toString();
		cout << ")";
	}
	else if(!this->rc){
		cout <<")"; return;
	}

}
#endif // !_TREE_H