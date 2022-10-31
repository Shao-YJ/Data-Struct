#ifndef _MATRIXGRAPH_H
#define _MATRIXGRAPH_H
#include"../std.h"

#define MAXSIZE 10

struct Edge{
	int v1;
	int v2;
	int wi;
};

static int edgeFind(int link[], int k) {
	while (link[k] >= 0)k = link[k];
	return k;
}

template<class T>
class MatrixGraph {
public:
	int type;//1为无向图，0为有向图
	int vn;//顶点个数
	int en;
	T Ve[MAXSIZE];
	int Vr[MAXSIZE][MAXSIZE] = { 0 };
	bool visited[MAXSIZE];
	int topolist[MAXSIZE] = {0};

	MatrixGraph(int t=1) { this->type = t; this->en = 0; }
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

	void Prim(int v);
	int getMinEdge(int lowcost[]);

	void edges(Edge e[]);
	void Kruskal(Edge e[]);

	void Dijkstra(int v);
	void Floyd();

	void TopoSort();
	void CriticalPath();
};

template<class T>
void MatrixGraph<T>::CriticalPath(){
	int i,j,v,size=this->vn;
	int ve[MAXSIZE] = { 0 }, vl[MAXSIZE];
	for (i = 0; i < size; i++) {
		vl[i] = -1;
		v = this->topolist[i];
		for (j = 0; j < size; j++) 
			if(this->Vr[v][j])
				if (this->Vr[v][j] + ve[v] > ve[j] || ve[j] == 0)
					ve[j] = this->Vr[v][j] + ve[v];
	}
	vl[size - 1] = ve[size - 1];
	for (i = size-1; i >=0; i--) {
		v = this->topolist[i];
		for (j = 0; j < size; j++)
			if (this->Vr[j][v])
				if (vl[v]- this->Vr[j][v] < vl[j] || vl[j] == -1)
					vl[j] = vl[v]- this->Vr[j][v];
	}
	for (i = 0; i < size; i++)
		if (vl[this->topolist[i]] == ve[this->topolist[i]])
			cout << this->topolist[i] << " ";
}

template<class T>
void MatrixGraph<T>::TopoSort() {
	int n = 0, r = 0, i, j, size = this->vn, p;
	int ID[MAXSIZE] = { 0 };
	for (i = 0; i < size; i++) {
		ID[i] = 0;
		for (j = 0; j < size; j++) 
			if (this->Vr[j][i])
				ID[i]++;
		if (ID[i] == 0)
			this->topolist[r++]=i;
	}
	if (r==0) {
		cout << "No topolist";
		return;
	}
	while (r > n) {
		p = this->topolist[n++];
		for (i = 0; i < size; i++)
			if (this->Vr[p][i]) {
				ID[i]--;
				if (ID[i] == 0)
					this->topolist[r++] = i;
			}
	}
	//if (n < size)
	//	cout << "There is a loop.";
	//else 
	//	for (i = 0; i < size; i++)
	//		cout << this->topolist[i] << " ";
}

template<class T>
void MatrixGraph<T>::Floyd(){
	int Wi[MAXSIZE][MAXSIZE] = {0}, path[MAXSIZE][MAXSIZE][MAXSIZE] = { 0 };
	int i, j, k,x,size=this->vn;
	for (i = 0; i < size; i++)
		for (j = 0; j < i; j++) {
			Wi[i][j] =Wi[j][i]= this->Vr[i][j];
			if (Wi[i][j]) {
				path[i][j][i] = path[i][j][j] = 1;
				path[j][i][i] = path[j][i][j] = 1;
			}
		}
	for(i=0;i<size;i++)
		for (j = i; j < size; j++) {
			x = -1;
			for(k=0;i!=j&&k<size;k++)
				if (Wi[i][k] && Wi[k][j] && (Wi[i][k] + Wi[k][j] < Wi[i][j] || !Wi[i][j])) {
					x = k;
					Wi[i][j] = Wi[i][k] + Wi[k][j];
					Wi[j][i] = Wi[i][k] + Wi[k][j];
				}
			if (x > -1) {
				path[i][j][i] = path[i][j][j] = path[i][j][x] = 1;
				path[j][i][i] = path[j][i][j] = path[j][i][x] = 1;
			}
		}
	//for (i = 0; i < size; i++) 输出结果
	//{
	//	for (j = 0; j < size; j++)
	//	{
	//		for (k = 0; k < size; k++)
	//			cout << path[i][j][k] << "-";
	//		cout << ">" << Wi[i][j]<<"\t";
	//	}
	//	cout << endl;
	//} 
}

template<class T>
void MatrixGraph<T>::Dijkstra(int v){
	int i,j,k,s,min,length[MAXSIZE],list[MAXSIZE];
	this->setVisited();
	this->visited[v] = true;
	for (i = 0; i < this->vn; i++) {
		length[i] = this->Vr[v][i];
		list[i] = v;
	}
	list[v] = -1;
	for (i = 0; i < this->vn; i++) {
		min = INT_MAX; k = 0;
		for (j = 0; j < this->vn; j++)
			if (!this->visited[j] && length[j] < min&&length[j]>0) {
				k = j; min = length[j];
			}
		this->visited[k] = true;
		for (j = 0; j < this->vn; j++) {
			if (this->Vr[k][j] == 0|| this->visited[j])
				continue;
			s = length[k] + this->Vr[k][j];
			if (s < length[j]||length[j]==0) {
				length[j] = s;
				list[j] = k;
			}
		}
	}
	for (i = 0; i < this->vn; i++) {
		j = i;
		cout << "Path:" << j;
		j = list[j];
		while (j != -1) {
			cout << "->" << j;
			j = list[j];
		}
		cout << "\tlength:" << length[i] << endl;
	}
}

template<class T>
void MatrixGraph<T>::Kruskal(Edge e[]){
	int link[MAXSIZE]; edgeSort(e, this->vn);
	int i, v1, v2;
	for (i = 0; i < this->vn; i++) 
			link[i] = -1;
	for (i = 0; i < this->en; i++) {
		v1 = edgeFind(link, e[i].v1);
		v2 = edgeFind(link, e[i].v2);
		if (v1 != v2) {
			if(link[e[i].v2]>=0)
				link[e[i].v1] = e[i].v2;
			else
				link[e[i].v2] = e[i].v1;
			cout << e[i].v1 << " " << e[i].v2 << " " << e[i].wi << endl;
		}
	}
}

template<class T>
void MatrixGraph<T>::edges(Edge e[]){
	int n = 0;
	for(int i=0;i<this->vn;i++)
		for (int j = i; j < this->vn; j++) 
			if(this->Vr[i][j]){
				e[n].v1 = i;
				e[n].v2 = j;
				e[n++].wi = this->Vr[i][j];
			}
}

template<class T>
void MatrixGraph<T>::Prim(int v) {
	int i, j, z, k;
	int lowcost[2][MAXSIZE];
	//第0行存储双亲结点，第1行存储当前树中结点与不在树中结点的邻接点的权值
	this->setVisited();
	this->visited[v] = true;

	//根据根节点，对最小代价表进行初始化
	for (i = 0; i < this->vn; i++) {
		lowcost[0][i] = v;
		lowcost[1][i] = this->Vr[v][i];
	}
	//进行size-1次，找到除根节点外剩下的结点
	for (i = 0; i < this->vn - 1; i++) {
		k = this->getMinEdge(lowcost[1]);//找到当前权值最小结点
		this->visited[k] = true;
		for (j = 0; j < this->vn; j++) {
			//判断条件有两个，前提都是结点未访问，一个是lowcost中权值未赋值，仍未0，
			//一种是lowcost权值已赋值，但权值小于新加入结点与同一邻接点的权值
			if (!this->visited[j] && !lowcost[1][j] || 
				!this->visited[j] && this->Vr[k][j] < lowcost[1][j] && this->Vr[k][j]) {
				lowcost[0][j] = k;
				lowcost[1][j] = this->Vr[k][j];
			}
		}
	}
}

//根据lowcost表找到权值最小结点
template<class T>
int MatrixGraph<T>::getMinEdge(int lowcost[]) {
	int min = INT_MAX, locate = -1;
	for (int i = 0; i < this->vn; i++)
	{
		//权值不能为0
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
	for (int i = 0; i < this->vn; i++)
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
	for (int i = 0; i < this->vn; i++)
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
		for (int i = 0; i < en; i++) 
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
	for (int i = 0; i < this->vn; i++)
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

template<class T>//找出第一个邻接点
int MatrixGraph<T>::firstAdjV(int v){
	for (int i = 0; i < this->vn; i++)
		if (this->Vr[v][i] != 0)
			return i;
	return -1;
}

template<class T>//在当前邻接点基础上找下一个邻接点
int MatrixGraph<T>::nextAdjV(int v, int w){
	for (int i = w+1; i < this->vn; i++)
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
	for (int i = 0; i < this->en; i++)
		this->visited[i] = false;
}

template<class T>
int MatrixGraph<T>::TD(T e){
	int i, site = 0;
	int ID = 0,OD=0;
	for (i = 0; i < this->vn; i++)
		if (Ve[i] == e) {
			site = i; break;
		}
	if (site == -1 || site == this->vn) {
		cout << "No such element!";
		return NULL;
	}
	if (this->type) {
		for (i = 0; i < this->vn; i++) {
			if (this->Vr[i][site])
				ID++;
		}
		return ID;
	}
	else {
		for (i = 0; i < this->vn; i++) {
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
	this->vn = s;
	for (int i = 0; i < s; i++)
		Ve[i] = list[i];
}

template<class T>
void MatrixGraph<T>::create() {
	int v1, v2, w;
	this->en = 0;
	//根据表类型创建有向图或无向图
	if (this->type) {//有向图
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			this->Vr[v1][v2] = w;
			this->Vr[v2][v1] = w;
			cin >> v1 >> v2 >> w;
			this->en++;
		}
	}
	else {//无像图
		cin >> v1 >> v2 >> w;
		while (v1 != v2) {
			this->Vr[v1][v2] = w;
			cin >> v1 >> v2 >> w;
			this->en++;
		}
	}
}

template<class T>
void MatrixGraph<T>::toString() {
	cout << "Vr\t";
	int i, j;
	int num = this->vn;
	for (i = 0; i < num; i++)
		cout << this->Ve[i] << "\t";
	cout << endl;
	for (i = 0; i < vn; i++) {
		cout << Ve[i] << "\t";
		for (j = 0; j < vn; j++)
			cout << Vr[i][j] << "\t";
		cout << endl;
	}
}

#endif // !_MATRIXGRAPH_H