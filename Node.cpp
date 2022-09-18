#include "Node.h"

void initList(LinkList &L) {
	L = (LinkList)malloc(sizeof(Node));
	if (!L) {
		cout << "init error";
		return;
	}
	L->data = 0;
	L->next = NULL;
}

void cirinitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(Node));
	if (!L) {
		cout << "init error";
		return;
	}
	L->data = 0;
	L->next = L;
}

void insertList(LinkList& L,int e) {
	LinkList p = (LinkList)malloc(sizeof(Node));
	if (!p) {
		cout << "init error";
		return;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
}

void insertListEnd(LinkList& L, int e) {
	LinkList p = (LinkList)malloc(sizeof(Node));
	if (!p) {
		cout << "init error";
		return;
	}
	p->data = e;
	p->next = NULL;
	LinkList temp = L;
	while (temp->next)
		temp= temp->next;
	temp->next = p;
}

void ListToString(LinkList& L) {
	LinkList p = L;
	while (p->next&&p->next!=L) {
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

void insertNList(LinkList& L, int *a,int n) {
	LinkList temp = L;
	LinkList p;
	for (int i = 0; i < n; i++) {
		//p = (LinkList)malloc(sizeof(Node));
		//if (!p)
		//	return;
		////cout << a[i];
		//p->data = a[i];
		//p->next = NULL;
		//temp->next = p;
		//temp = temp->next;
		insertList(temp, a[i]);
	}
}

void deleteList(LinkList& L, int i) {
	LinkList p = L;
	for (int j = 0; j < i-1; j++) {
		if (!p)
			return;
		p = p->next;
	}
	LinkList temp = p->next;
	p->next = temp->next;
	free(temp);
}

void mergeList(LinkList& L, LinkList& R) {
	LinkList p = L->next, _p = L, q = R->next;
	while (q) {
		while (p!=NULL&&p->data < q->data)
		{
			_p = p; p = p->next;
		}
		_p->next = q;
		if (!p)
			break;
		_p = q; 
		q = q->next;
		_p->next = p;
	}
	free(R);
}

void connectList(LinkList& L, LinkList& R) {
	LinkList l=L, r=R;
	while (l->next && r->next) {
		l = l->next;
		r = r->next;
	}
	if (!l->next) {
		l->next = R->next;
		free(R);
	}
	else {
		r->next = L->next;
		free(L);
	}
}

void circularMerge(LinkList& L, LinkList& R) {
	LinkList p = L->next;
	L->next = R->next->next;
	R->data = R->next->data;
	free(R->next);
	R->next = p;
}

void josephus(LinkList& L,int n, int k, int m) {
	LinkList p=L,temp;
	int i=0;
	while (i < k) {
		p = p->next;
		i++;
	}
	for (int j = 0; j < n; j++) {
		i = 0;
		while (i < m-1)
		{
			p = p->next;
			if (p != L)
				i++;
		}
		if (p->next == L)
			p = p->next;
		cout << p->next->data << " ";
		temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

void initDList(LinkList& L) {

}