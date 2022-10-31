#ifndef _SEARCH_H
#define _SEARCH_H

template<typename T>
int Search(T L[], T key, int n)
{
	int i;
	L[0] = key;  // �ڱ�
	for (i = n; L[i] != key; --i);
	return i;
} //�㷨��ʱ�临�Ӷ�ΪO(n)

template<typename Type>
int BiSearch(Type L[], Type key, int n)
{
	int mid,left = 1, right = n;	//�������ֵ
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key == L[mid]) return mid;
		if (key < L[mid]) right = mid - 1;
		else left = mid + 1;
	} return -1;	//���Ҳ��ɹ�
} //�۰�����㷨��ʱ�临�Ӷ�ΪO(logn)

template<typename T>
struct IndexList{
	T index;
	int start;
	int length;
};
static IndexList<int> LI[10];

template<typename T>
int BlockSearch(T L[],int m, T key) 	//mΪLI�ĳ���
{
	int i,j;
	for (i = 0; i < m; ++i)
		if (key <= LI[i].index) break;
	if (i == m) return 0;	//û���ҵ���Ӧ�߼��ӱ�
	j = LI[i].start;		//�߼��ӱ�ʼ��¼
	while (j < LI[i].start + LI[i].length)
		if (key == L[j].key) return j; 	//���ҳɹ�
		else ++j;
	return 0;	//���Ҳ��ɹ�
}

template<class T>
class BinaryTree{
public:
	T key; //�ؼ���
	//ElemType* otherinfo;
	BinaryTree<T>* lc; //��ָ��
	BinaryTree<T>* rc; //��ָ��

	BinaryTree(T e) { key = e; lc = rc = NULL; };
	int SearchT(T e);
	BinaryTree<T>* SearchT(T e, BinaryTree<T>* &p);
	int insertT(T e);
	int deleteT(T e);
};

template<class T>
int BinaryTree<T>::SearchT(T e)
{
	if (!this) return 0;  //���Ҳ��ɹ�
	if (e == this->key) return 1;  //���ҳɹ�
	if (e < this->key)  //��������
		return this->lc->SearchT(e);
	return this->rc->SearchT(e);
} // SearchT

template<class T>
BinaryTree<T>* BinaryTree<T>::SearchT(T e, BinaryTree<T>* &p){
	if (!this) return 0;  //���Ҳ��ɹ�
	if (e == this->key) return this;
	p = this;
	if (e < this->key)
		return this->lc->SearchT(e,p);
	return this->rc->SearchT(e,p);
} // SearchT

template<class T>
int BinaryTree<T>::insertT(T e) {
	BinaryTree<T>* p=this;
	if (this->SearchT(e, p))return 0;
	else {
		BinaryTree<T>* t = new BinaryTree<T>(e);
		t->lc = t->rc = NULL;
		if (e < p->key)p->lc = t;
		else p->rc = t;
		return 1;
	}
}

template<class T>
int BinaryTree<T>::deleteT(T e) {
	BinaryTree<T>* p = this;
	BinaryTree<T>* q = this->SearchT(e, p);
	if (!q)return 0;
	if (!q->lc && !q->rc) delete q;
	else if (q->lc && q->rc) {
		BinaryTree<T>* next;
		p = q; next = q->lc;
		while (next->rc) {
			q = next;
			next = next->rc;
		}
		p->key = next->key;
		if (p == q) 
			p->lc = next->lc;
		else q->rc = next->lc;
		delete next;
	}
	else if (q->lc) {
		if (p->lc == q) 
			p->lc = q->lc;
		else if (p->rc==q) 
			p->rc = q->lc;
		delete q;
	}
	else if (q->rc) {
		if (p->lc == q) 
			p->lc = q->rc;
		else if (p->rc == q) 
			p->rc = q->rc;
		delete q;
	}
	return 1;
}
#endif // !_SEARCH_H
