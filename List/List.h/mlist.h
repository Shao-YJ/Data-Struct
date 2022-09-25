#pragma once
#include"../../std.h"

typedef struct{
	int* elem;
	int n;
	int N;
}Mlist;

void initMlist(Mlist &L, int length);

void MlisttoString(Mlist L);

void insertMlist(Mlist &L, int e);
void insertMlist(Mlist& L, int i, int e);

void deleteMlist(Mlist& L, int i);

int locateMlist(Mlist& L, int e);

void mergeMlist(Mlist L, Mlist R, Mlist& LR);

bool MlistisEmpty(Mlist L);

void freeMlist(Mlist& L);

//listË³Ðò±íÄ£°å
template<typename T>
class MList {
public:
	MList(int length);
	T* elem;
	int n;
	int size;

	void toString();
	void insert(T e,int i=-1);
	void del(int i);

	template<typename S>
	friend istream& operator>>(istream& cin, MList<S>& st);
};

template<typename T>
istream& operator>>(istream& in,  MList<T>&st)
{
	in >>st.elem;
	return in;
}

template<typename T>
MList<T>::MList(int length) {
	this->n = 0;
	this->size = length;
	this->elem = (T*)malloc(length * sizeof(T));
	if (!this->elem)
	{
		cout << "init errof";
		return;
	}
}

template<typename T>
void MList<T>::toString() {
	for (int i = 0; i < this->n; i++)
		cout << this->elem[i] << " ";
	cout << endl;
}


template<typename T>
void MList<T>::insert(T e, int i) {
	T* new_elem;
	if (this->n == this->size)
	{
		new_elem = (T*)realloc(this->elem, 2 * this->size * sizeof(T));
		if (!new_elem)
			return;
		this->elem = new_elem;
		this->size = 2 * this->size;
	}
	if (i == -1)
	{
		this->elem[this->n++] = e;
		return;
	}
	for (int j = this->n; j >= i - 1; j--)
		this->elem[j + 1] = this->elem[j];
	this->elem[i - 1] = e;
	this->n++;
}

template<typename T>
void MList<T>::del(int i) {
	if (i >= this->n || i < 0)
	{
		cout << "delete error index" << endl;
		return;
	}
	for (int j = i - 1; j < this->n; j++)
		this->elem[j] = this->elem[j + 1];
	this->n--;
}






