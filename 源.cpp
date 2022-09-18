#include<iostream>
#include<stdlib.h>
#include"mlist.h"
#include"Node.h"
using namespace std;

int main() {

	/*LinkList node;
	cirinitList(node);
	
	insertList(node, 100);
	insertList(node, 131);

	ListToString(node);

	int a[5] = { 1,92,125,154,165 };
	LinkList node1;
	cirinitList(node1);
	insertNList(node1,a,5);
	ListToString(node1);

	mergeList(node, node1);
	connectList(node, node1);
	ListToString(node);
	
	circularMerge(node, node1);
	ListToString(node);
	
	josephus(node,7,2,2);*/

	DLinkList dnode;
	initDList(dnode);
	insertDList(dnode, 12);
	insertDList(dnode, 123);
	insertDList(dnode, 1562);
	insertDList(dnode, 152);
	insertDList(dnode, 156);

	insertDList(dnode, 3, 0);

	ListToString(dnode);

	deleteDList(dnode, 2);
	ListToString(dnode);

	return 0;
}

