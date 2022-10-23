#ifndef _GRAPH_H
#define _GRAPH_H
#include"../std.h"

#define MAXSIZE 10

template<class T>
class MatrixGraph {
public:
	int type;//1为无向图，0为有向图
	int size;//顶点个数
	int n;
	T Ve[MAXSIZE];
	int Vr[MAXSIZE][MAXSIZE] = { 0 };
	bool visited[MAXSIZE];

	MatrixGraph(int t=1) { this->type = t; this->n = 0; }
	void create();
	void toString();
	void setVe(T list[], int s);
	int TD(T e);
	void setVisited();
	void visit(int v);
	int firstAdjV(int v);
	int nextAdjV(int v, int w);
	void DFS(int v);
	void DFSTraverse(int v);
};

template<class T>
void MatrixGraph<T>::DFSTraverse(int v) {
	this->setVisited();
	DFS(v);
	for (int i = 0; i < this->size; i++)
		if (!this->visited[i])
			DFS(i);
}

template<class T>
void MatrixGraph<T>::DFS(int v){
	this->visit(v); this->visited[v] = true;
	for (int k = this->firstAdjV(v); k >= 0; k = this->nextAdjV(v,k)) {
		if (!this->visited[k])
			this->DFS(k);
	}
}

template<class T>
int MatrixGraph<T>::firstAdjV(int v){
	for (int i = 0; i < this->size; i++)
		if (this->Vr[v][i] != 0)
			return i;
	return -1;
}

template<class T>
int MatrixGraph<T>::nextAdjV(int v, int w){
	for (int i = w+1; i < this->size; i++)
		if (this->Vr[v][i] != 0)
			return i;
	return -1;
}

template<class T>
void MatrixGraph<T>::visit(int v){
	cout << this->Ve[v];
}

template<class T>
void MatrixGraph<T>::setVisited(){
	for (int i = 0; i < this->n; i++)
		this->visited[i] = false;
}

template<class T>
int MatrixGraph<T>::TD(T e){
	int i, site = 0;
	int ID = 0,OD=0;
	for (i = 0; i < this->size; i++)
		if (Ve[i] == e) {
			site = i; break;
		}
	if (site == -1 || site == this->size) {
		cout << "No such element!";
		return NULL;
	}
	if (this->type) {
		for (i = 0; i < this->size; i++) {
			if (this->Vr[i][site])
				ID++;
		}
		return ID;
	}
	else {
		for (i = 0; i < this->size; i++) {
			if (this->Vr[i][site])
				ID++;
			if (this->Vr[site][i])
				OD++;
		}
		return ID + OD;
	}
}

template<class T>
void MatrixGraph<T>::setVe(T list[], int s) {
	this->size = s;
	for (int i = 0; i < s; i++)
		Ve[i] = list[i];
}

template<class T>
void MatrixGraph<T>::create() {
	int v1, v2, w;
	this->n = 0;
	//根据表类型创建有向图或无向图
	if (this->type) {//无向图
		cin >> v1 >> v2;
		while (v1 != v2) {
			this->Vr[v1][v2] = 1;
			this->Vr[v2][v1] = 1;
			cin >> v1 >> v2;
			this->n++;
		}
	}
	else {//有像图
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			this->Vr[v1][v2] = w;
			cin >> v1 >> v2 >> w;
			this->n++;
		}
	}
	cout << endl;
}

template<class T>
void MatrixGraph<T>::toString() {
	cout << "Vr\t";
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

//----邻接表----
template<class T>
class ENode {
public:
	int Vi;
	int Wi;
	ENode<T>* next;

	ENode(int v, int w);
	ENode() {};
};

template<class T>
ENode<T>::ENode(int v, int w) {
	this->Vi = v;
	this->Wi = w;
	this->next = NULL;
}

template<class T>
class VNode {
public:
	T data;
	ENode<T> *head;

	VNode(T e);
	VNode() { this->head = NULL; };
};

template<class T>
VNode<T>::VNode(T e){
	this->data = e;
	this->head = NULL;
}

template<class T>
class ListGraph {
public:
	VNode<T> Ve[MAXSIZE];
	int vn;
	int en;
	int type;//1为无向图，2为有向图
	bool visited[MAXSIZE];

	ListGraph(T e[], int n,int t);
	void create();
	void toString();
	void visit(int v);
	
	void setVisited();
	void DFS(int v);
	void DFSTraverse(int v);
};

template<class T>
void ListGraph<T>::DFSTraverse(int v) {
	this->setVisited();
	this->DFS(v);
	for (int i = 0; i < this->vn; i++)
		if (!this->visited[i])
			this->DFS(i);
}

template<class T>
void ListGraph<T>::DFS(int v){
	this->visit(v); this->visited[v] = true;
	ENode<T>* p = this->Ve[v].head;
	while (p) {
		if (!this->visited[p->Vi])
			DFS(p->Vi);
		p = p->next;
	}
}

template<class T>
void ListGraph<T>::visit(int v){
	cout << this->Ve[v].data;
}

template<class T>
void ListGraph<T>::setVisited(){
	for (int i = 0; i < this->vn; i++)
		visited[i] = false;
}

template<class T>
void ListGraph<T>::toString(){
	ENode<T>* p;
	for (int i = 0; i < this->vn; i++) {
		cout << i<<"\t"<<this->Ve[i].data<<":"<<i;
		p = Ve[i].head;
		while (p) {
			cout << "->" << p->Vi;
			p = p->next;
		}
		cout << endl;
	}
}

template<class T>
ListGraph<T>::ListGraph(T e[], int n,int t){
	this->en = 0;
	this->setVisited();
	this->type = t;
	this->vn = n;
	for (int i = 0; i < n; i++)
		this->Ve[i] = e[i];
}

template<class T>
void ListGraph<T>::create() {
	int v1, v2, w;
	this->en = 0;
	ENode<T>* p;
	//根据表类型创建有向图或无向图
	if (this->type) {//无向图
		cin >> v1 >> v2;
		while (v1 != v2) {
			p = new ENode<T>(v2, 1);
			p->next = this->Ve[v1].head;
			this->Ve[v1].head = p;
			p = new ENode<T>(v1, 1);
			p->next = this->Ve[v2].head;
			this->Ve[v2].head = p;
			this->en++;
			cin >> v1 >> v2;
		}
	}
	else {//有像图
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			p = new ENode<T>(v2, w);
			p->next = this->Ve[v1].head;
			this->Ve[v1].head = p;
			this->en++;
			cin >> v1 >> v2>>w;
		}
	}
}
#endif // !_GRAPH_H