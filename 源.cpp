#include"std.h"

int main() {

	LinkList L1, L2;
	initList(L1);

	int a[10] = { 1,5,6,3,4653,6543,7654,2,3,54 };
	insertNList(L1, a, 10);
	ListToString(L1);
	listReverse(L1,L2);
	ListToString(L2);
	
	return 0;
}