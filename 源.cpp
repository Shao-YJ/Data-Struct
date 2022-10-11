#include"std.h"
#include"Test.h"

int main() {

	BTree<char> t,head,*pre;
	string str;

	while (cin >> str) {
		int k = 0;
		t.create(str, k);
		head = BTree<char>(0);
		pre = NULL;
		//t.inThreading(t.lc, pre);
		BTree<char>::postThreading(t.lc, pre);
		//pre = &head;
		BTree<char>::postOrderTraverse(t.lc);
	}
	return 0;
}