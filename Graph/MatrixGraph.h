#ifndef _MATRIXGRAPH_H
#define _MATRIXGRAPH_H
#include"../std.h"

#define MAXSIZE 10

template<class T>
class MatrixGraph {
public:
	int type;//1Ϊ����ͼ��0Ϊ����ͼ
	int size;//�������
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

	void BFS(int v);
	void BFSTraverse(int v);

	bool path(int v1, int v2);

	void prim(int v);
	int getMinEdge(int lowcost[]);
};

template<class T>
void MatrixGraph<T>::prim(int v) {
	int i, j, z, k;
	int lowcost[2][MAXSIZE];
	//��0�д洢˫�׽�㣬��1�д洢��ǰ���н���벻�����н����ڽӵ��Ȩֵ
	this->setVisited();
	this->visited[v] = true;

	//���ݸ��ڵ㣬����С���۱���г�ʼ��
	for (i = 0; i < this->size; i++) {
		lowcost[0][i] = v;
		lowcost[1][i] = this->Vr[v][i];
	}
	//����size-1�Σ��ҵ������ڵ���ʣ�µĽ��
	for (i = 0; i < this->size - 1; i++) {
		k = this->getMinEdge(lowcost[1]);//�ҵ���ǰȨֵ��С���
		this->visited[k] = true;
		for (j = 0; j < this->size; j++) {
			//�ж�������������ǰ�ᶼ�ǽ��δ���ʣ�һ����lowcost��Ȩֵδ��ֵ����δ0��
			//һ����lowcostȨֵ�Ѹ�ֵ����ȨֵС���¼�������ͬһ�ڽӵ��Ȩֵ
			if (!this->visited[j] && !lowcost[1][j] || 
				!this->visited[j] && this->Vr[k][j] < lowcost[1][j] && this->Vr[k][j]) {
				lowcost[0][j] = k;
				lowcost[1][j] = this->Vr[k][j];
			}
		}
	}
}

//����lowcost���ҵ�Ȩֵ��С���
template<class T>
int MatrixGraph<T>::getMinEdge(int lowcost[]) {
	int min = INT_MAX, locate = -1;
	for (int i = 0; i < this->size; i++)
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
bool MatrixGraph<T>::path(int v1, int v2){
	this->visited[v1] = true;
	for (int i = 0; i < this->size; i++)
		if (this->Vr[v1][i] && !this->visited[i]) {
			if (i == v2) 
				return true;
			if (this->path(i, v2))
				return true;
		}
	return false;
}

template<class T>
void MatrixGraph<T>::BFSTraverse(int v){
	this->setVisited();
	this->BFS(v);
	for (int i = 0; i < this->size; i++)
		if (!this->visited[i])
			BFS(i);
}

template<class T>
void MatrixGraph<T>::BFS(int v){
	queue<int> vq;
	this->visited[v] = true;
	vq.push(v);
	while (!vq.empty()) {
		v = vq.front();
		vq.pop();
		this->visit(v);
		for (int i = 0; i < n; i++) 
			if (this->Vr[v][i] && !this->visited[i]) {
				vq.push(i);
				this->visited[i] = true;
			}
	}
}

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

template<class T>//�ҳ���һ���ڽӵ�
int MatrixGraph<T>::firstAdjV(int v){
	for (int i = 0; i < this->size; i++)
		if (this->Vr[v][i] != 0)
			return i;
	return -1;
}

template<class T>//�ڵ�ǰ�ڽӵ����������һ���ڽӵ�
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
	//���ݱ����ʹ�������ͼ������ͼ
	if (this->type) {//����ͼ
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			this->Vr[v1][v2] = w;
			this->Vr[v2][v1] = w;
			cin >> v1 >> v2 >> w;
			this->n++;
		}
	}
	else {//����ͼ
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			this->Vr[v1][v2] = w;
			cin >> v1 >> v2 >> w;
			this->n++;
		}
	}
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

#endif // !_MATRIXGRAPH_H