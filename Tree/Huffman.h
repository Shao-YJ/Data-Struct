#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include"../std.h"

template<class T>
class HuffmanNode {
public:
	T data;
	int w;
	int parent;
	int lc;
	int rc;

	HuffmanNode(T e, int Weight, int Lc=NULL, int Rc=NULL, int Parent = NULL);
	void toString();
};

template<class T>
void HuffmanNode<T>::toString() {
	cout << this->data << "\t"<< this->w << "\t"<< this->parent << "\t"<<this->lc << "\t" << this->rc << endl;
}

template<class T>
HuffmanNode<T>::HuffmanNode(T e, int Weight, int Lc, int Rc, int Parent)
{
	this->data = e;
	this->w = Weight;
	this->parent = Parent;
	this->lc = Lc;
	this->rc = Rc;
}

template<typename T>
void Huffman() {
	int n,i=0,j=0;
	T e;
	int weight;
	cin >> n;
	MList<HuffmanNode<T>> hufflist(2 * n - 1);

	for (i = 0; i < n; i++) {
		cin >> e >> weight;
		hufflist.elem[i]=HuffmanNode<T>(e, weight);
	}
	
	int min1, min2,locate1,locate2;
	for (i = n; i < 2*n - 1; i++) {
		min1 = INT_MAX, min2 = INT_MAX;
		locate1 = -1; locate2 = -1;
		for (j = 0; j < i; j++) {
			if (hufflist.elem[j].w <= min1 && hufflist.elem[j].parent == NULL) {
				min2 = min1;
				locate2 = locate1;
				min1 = hufflist.elem[j].w;
				locate1 = j;
			}
			else if (hufflist.elem[j].w <= min2 && hufflist.elem[j].parent == NULL) {
				min2 = hufflist.elem[j].w;
				locate2 = j;
			}
		}
		hufflist.elem[locate1].parent = i;
		hufflist.elem[locate2].parent = i;
		hufflist.elem[i]=HuffmanNode<T>('A'+i, hufflist.elem[locate1].w + hufflist.elem[locate2].w, locate1, locate2);
		hufflist.elem[i].toString();
		//list.elem[i].w = list.elem[locate1].w + list.elem[locate2].w;
		//list.elem[i].lc = locate1;
		//list.elem[i].lc = locate2;
	}

	for (i = 0; i < 2 * n - 1; i++) {
		cout << i << ":\t";
		hufflist.elem[i].toString();
	}
}

#endif // !_HUFFMAN_H