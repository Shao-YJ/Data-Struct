#pragma once
#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node,*LinkList;

void initList(LinkList& L);
void cirinitList(LinkList& L);

void insertList(LinkList& L,int e);
void insertListEnd(LinkList& L, int e);

void ListToString(LinkList& L);

void insertNList(LinkList& L, int* a, int n);

void deleteList(LinkList& L, int i);

void mergeList(LinkList& L, LinkList& R);

void connectList(LinkList& L, LinkList& R);

void circularMerge(LinkList& L, LinkList& R);

void josephus(LinkList& L, int n,int k, int m);

typedef struct DNode {
	struct DNode* front;
	int data;
	struct DNode* next;
}DNode,*DLinkList;

void initDList(DLinkList& L);

void insertDList(DLinkList& L, int n, int e);
void insertDList(DLinkList& L, int e);

void ListToString(DLinkList& L);

void deleteDList(DLinkList& L, int i);