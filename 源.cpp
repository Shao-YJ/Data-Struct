#include"std.h"

int main() {

	BTree<char> t;
	string str;
	cin >> str;
	int k = 0;
	t.create(str, k);

	return 0;
}