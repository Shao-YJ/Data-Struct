#include "../List.h/MList.h"

void initMlist(Mlist &L, int length) {
	L.elem = (int*)malloc(length * sizeof(int));
	if (!L.elem)
	{
		cout << "init erroe";
		return;
	}
	L.n = 0;
	L.N = length;
}

void MlisttoString(Mlist L) {
	for (int i = 0; i < L.n; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

void insertMlist(Mlist& L, int e)
{
	int* new_elem;
	if (L.n == L.N)
	{
		new_elem = (int*)realloc(L.elem, 2 * L.N * sizeof(int));
		if (!new_elem)
			return;
		L.elem = new_elem;
		L.N = 2 * L.N;
	}
	L.elem[L.n++] = e;
}

void insertMlist(Mlist& L, int i, int e) {
	int* new_elem;
	if (L.n == L.N)
	{
		new_elem = (int*)realloc(L.elem, 2 * L.N * sizeof(int));
		if (!new_elem)
			return;
		L.elem = new_elem;
		L.N = 2 * L.N;
	}
	for (int j = L.n; j >= i-1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = e;
	L.n++;
}

void deleteMlist(Mlist& L, int i) {
	if (i >= L.n || i < 0)
	{
		cout << "delete error index" << endl;
		return;
	}
	for (int j = i-1; j < L.n; j++)
		L.elem[j] = L.elem[j + 1];
	L.n--;
}

int locateMlist(Mlist& L, int e) {
	for (int i = 0; i < L.n; i++)
		if (L.elem[i] == e)
			return i+1;
	return 0;
}

void mergeMlist(Mlist L, Mlist R, Mlist& LR)
{
	int l = 0; 
	int r = 0;
	while (l < L.n && r < L.n) {
		if (L.elem[l]<=R.elem[r])
			LR.elem[LR.n++] = L.elem[l++];
		else
			LR.elem[LR.n++] = R.elem[r++];
	}
	while (r < R.n) {
		LR.elem[LR.n++] = R.elem[r++];
	}
	while (l < L.n) {
		LR.elem[LR.n++] = L.elem[l++];
	}
}

bool MlistisEmpty(Mlist L) {
	return !L.n;
}

void freeMlist(Mlist& L) {
	if (L.elem)
	{
		free(L.elem);
		L.N = L.n = 0;
	}
}