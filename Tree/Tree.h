#ifndef _TREE_H
#define _TREE_H
#include"../std.h"

template<class T>
class Tree {
public:
	T data;
	Tree* lc;
	Tree* rc;

	Tree() { this->lc = this->rc = NULL; };
	Tree(T e);
	void create(string str,int k);
};

template<class T>
inline Tree<T>::Tree(T e){
	this->data = e;
	this->lc = this->rc = NULL;
}

template<class T>
void Tree<T>::create(string str,int k)
{
	int i = 0;
	char ch = str[i];
	while (ch) {
		if (ch >= 65 && ch <= 90 || ch >= 97 && <= 122)
		{
			Tree t(ch);
			if (str[i - 1] == ",")this->rc = t;
			else this->lc = t;
		}
		if (ch == "("||ch==")"||ch==",")ch++;
	}
}

#endif // !_TREE_H