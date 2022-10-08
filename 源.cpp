#include"std.h"
#include"Test.h"

int main() {

	BTree<char> t;
	string str;


	while (cin >> str) {
		int k = 0;
		t.create(str, k);
		inOrder(t);
	}
	return 0;
}