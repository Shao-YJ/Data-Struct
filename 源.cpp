#include"std.h"

int main() {

	BTree<char> t;
	string str;
	cin >> str;
	cout << treeDepth(str);
	return 0;
}