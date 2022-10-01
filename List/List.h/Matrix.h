#ifndef _MATRIX_H
#define _MATRIX_H
#include"../../std.h"

template<class T>
class Triple {
public:
	Triple() {};
	Triple(int y, int x, T data);
	void toString();
private:
	int row;
	int col;
	T value;
};

template<class T>
Triple<T>::Triple(int y, int x, T data) {
	this->row = y;
	this->col = x;
	this->value = data;
}

template<class T>
void Triple<T>::toString()
{
	cout << "(" << this->row << "," << this->col << "," << this->value << ") ";
}

template<class T>
class TMatrix {
public:
	TMatrix(int r, int c, int t);
	void push(Triple<T> node);
	void toString();
private:
	int rn;
	int cn;
	int tn;
	Triple<T> data[100];
};

template<class T>
TMatrix<T>::TMatrix(int r, int c, int t) {
	this->rn = r;
	this->cn = c;
	this->tn = t;
}

template<class T>
void TMatrix<T>::push(Triple<T> node) {
	this->data[this->tn++] = node;
}

template<class T>
void TMatrix<T>::toString() {
	int i = 0,num=this->tn;
	while (i < tn)
		this->data[i++].toString();
}

//ʮ������
typedef struct Clnode
{
	int row, col;   /*  �кź��к�  */
	int value;    /*  Ԫ��ֵ  */
	struct Clnode* down, * right;
}OLNode;

typedef struct
{
	int rn;        /*  ���������  */
	int cn;        /*  ���������  */
	int tn;        /*  ��0Ԫ������  */
	OLNode* rhead;
	OLNode* chead;
} CrossList;

//�����
template<class T>
class GLNode {
public:
	GLNode(int type, T value);
	GLNode(int type,GLNode *value)
private:
	int tag;/*  ��־��Ϊ1������;Ϊ0 ��ԭ�ӽ��  */
	union {
		T value;
		GLNode* hp;
	}data;
	GLNode* tp;
};/* �����������  */

template<class T>
inline GLNode<T>::GLNode(int type, T value)
{
	this->tag = type;
	this->data = value;
	this->tp = NULL;
}

template<class T>
inline GLNode<T>::GLNode(int type, GLNode* value) {
	this->tag = type;
	this->data = value;
	this->tp = NULL;
}
#endif // !_MATRIX_H