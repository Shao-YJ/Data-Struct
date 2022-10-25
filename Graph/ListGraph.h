#ifndef _LISTGRAPH_H
#define _LISTGRAPH_H
#include"../std.h"

#define MAXSIZE 10

//----�ڽӱ�----
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
	ENode<T>* head;

	VNode(T e);
	VNode() { this->head = NULL; };
};

template<class T>
VNode<T>::VNode(T e) {
	this->data = e;
	this->head = NULL;
}

template<class T>
class ListGraph {
public:
	VNode<T> Ve[MAXSIZE];
	int vn;
	int en;
	int type;//1Ϊ����ͼ��2Ϊ����ͼ
	bool visited[MAXSIZE];

	ListGraph(T e[], int n, int t);
	void create();
	void toString();
	void visit(int v);

	void setVisited();
	void DFS(int v);
	void DFSTraverse(int v);

	void BFS(int v);
	void BFSTraverse(int v);

	bool path(int v1, int v2);

	void prim(int v);
	int getMinEdge(int lowcost[]);
};

template<class T>
void ListGraph<T>::prim(int v){
	this->setVisited();
	this->visited[v] = true;
	ENode<T>* p = this->Ve[v].head;
	int lowcost[2][MAXSIZE] = {0},i,j,k;
	while (p) {
		lowcost[0][p->Vi] = v;
		lowcost[1][p->Vi] = p->Wi;
		p = p->next;
	}
	for (i = 0; i < this->vn - 1; i++) {
		for (j = 0; j < this->vn; j++) {
			cout << lowcost[1][j]<<" ";
		}
		cout << endl;
		k = this->getMinEdge(lowcost[1]);
		this->visited[k] = true;
		p = this->Ve[k].head;
		while (p) {
			cout << p->Vi << ":" << p->Wi << " ";
			j = p->Vi;
			if(!this->visited[j])
				if (!lowcost[1][j] || p->Wi < lowcost[1][j]) {
					lowcost[0][p->Vi] = k;
					lowcost[1][p->Vi] = p->Wi;
				}
			p = p->next;
		}
		cout << endl;
	}
	for (i = 0; i < this->vn; i++)
		cout << i << "\t";
	cout << endl;
	for (i = 0; i < this->vn; i++)
		cout << lowcost[0][i] << "\t";
	cout << endl;
	for (i = 0; i < this->vn; i++)
		cout << lowcost[1][i] << "\t";
}


//����lowcost���ҵ�Ȩֵ��С���
template<class T>
int ListGraph<T>::getMinEdge(int lowcost[]) {
	int min = INT_MAX, locate = -1;
	for (int i = 0; i < this->vn; i++)
	{
		//Ȩֵ����Ϊ0
		if (lowcost[i] < min && !this->visited[i] && lowcost[i]) {
			min = lowcost[i];
			locate = i;
		}
	}
	return locate;
}

template<class T>
bool ListGraph<T>::path(int v1,int v2) {
	ENode<T>* p = this->Ve[v1].head;
	int t;
	while (p) {
		t = p->Vi;
		if (!this->visited[t]) {
			this->visited[t] = true;
			if (t == v2)
				return true;
			if (this->path(t, v2))
				return true;
		}
		p = p->next;
	}
	return false;
}

template<class T>
void ListGraph<T>::BFSTraverse(int v) {
	this->setVisited();
	this->BFS(v);
	for (int i = 0; i < this->vn; i++)
		if (!this->visited[i])
			this->BFS(i);
}

template<class T>
void ListGraph<T>::BFS(int v) {
	ENode<T>* p = NULL;
	queue<ENode<T>*> q;
	q.push(this->Ve[v].head);
	this->visit(v);
	this->visited[v] = true;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		while (p) {
			if (!this->visited[p->Vi]) {
				this->visit(p->Vi);
				this->visited[p->Vi] = true;
				q.push(this->Ve[p->Vi].head);
			}
			p = p->next;
		}
	}
}

template<class T>
void ListGraph<T>::DFSTraverse(int v) {
	this->setVisited();
	this->DFS(v);
	for (int i = 0; i < this->vn; i++)
		if (!this->visited[i])
			this->DFS(i);
}

template<class T>
void ListGraph<T>::DFS(int v) {
	this->visit(v); this->visited[v] = true;
	ENode<T>* p = this->Ve[v].head;
	while (p) {
		if (!this->visited[p->Vi])
			DFS(p->Vi);
		p = p->next;
	}
}

template<class T>
void ListGraph<T>::visit(int v) {
	cout << this->Ve[v].data;
}

template<class T>
void ListGraph<T>::setVisited() {
	for (int i = 0; i < this->vn; i++)
		visited[i] = false;
}

template<class T>
void ListGraph<T>::toString() {
	ENode<T>* p;
	for (int i = 0; i < this->vn; i++) {
		cout << i << "\t" << this->Ve[i].data << ":" << i;
		p = Ve[i].head;
		while (p) {
			cout << "->" << p->Vi;
			p = p->next;
		}
		cout << endl;
	}
}

template<class T>
ListGraph<T>::ListGraph(T e[], int n, int t) {
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
	//���ݱ����ʹ�������ͼ������ͼ
	if (this->type) {//����ͼ
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			p = new ENode<T>(v2, w);
			p->next = this->Ve[v1].head;
			this->Ve[v1].head = p;
			p = new ENode<T>(v1, w);
			p->next = this->Ve[v2].head;
			this->Ve[v2].head = p;
			this->en++;
			cin >> v1 >> v2 >> w;
		}
	}
	else {//����ͼ
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			p = new ENode<T>(v2, w);
			p->next = this->Ve[v1].head;
			this->Ve[v1].head = p;
			this->en++;
			cin >> v1 >> v2 >> w;
		}
	}
}
#endif // !_LISTGRAPH_H