#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
	int* elem;
	int n;
	int N;
}Mlist;


void initMlist(Mlist &L, int length);

void MlisttoString(Mlist L);

void insertMlist(Mlist &L, int e);
void insertMlist(Mlist& L, int i, int e);

void deleteMlist(Mlist& L, int i);

int locateMlist(Mlist& L, int e);

void mergeMlist(Mlist L, Mlist R, Mlist& LR);

bool MlistisEmpty(Mlist L);

void freeMlist(Mlist& L);