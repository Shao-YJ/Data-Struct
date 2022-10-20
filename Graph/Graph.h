#ifndef _GRAPH_H
#define _GRAPH_H
#include"../std.h"

#define MAXSIZE 10

template<class T>
class Graph {
public:
	int size;
	int n;
	T Ve[MAXSIZE];
	int Vr[MAXSIZE][MAXSIZE] = { 0 };

	Graph() { this->n = 0; }
	void create();
	void toString();
	void setVe(T list[], int s);
};

template<class T>
void Graph<T>::setVe(T list[], int s) {
	this->size = s;
	for (int i = 0; i < s; i++)
		Ve[i] = list[i];
}

template<class T>
void Graph<T>::create() {
	int v1, v2, w;
	this->n = 0;
	cin >> v1 >> v2 >> w;
	while (v1 != v2) {
		this->Vr[v1][v2] = w;
		cin >> v1 >> v2 >> w;
		this->n++;
	}
}

template<class T>
void Graph<T>::toString() {
	cout << Vr << "\t";
	int i, j;
	int num = this->size;
	for (i = 0; i < num; i++)
		cout << this->Ve[i] << "\t";
	cout << endl;
	for (i = 0; i < size; i++) {
		cout << Ve[i] << "\t";
		for (j = 0; j < size; j++)
			cout << Vr[i][j] << "\t";
		cout << endl;
	}
}
#endif // !_GRAPH_H