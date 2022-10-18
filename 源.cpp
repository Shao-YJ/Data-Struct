#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	BTree<int> tree(0),c1(1),c2(2),c3(3),c4(4),c5(5), c6(6), c7(7), c8(8);
	tree.lc = &c1; tree.rc = &c2;
	c1.lc = &c3; c1.rc = &c4; c2.lc = &c5; c2.rc = &c6;
	c3.lc = &c7; c3.rc = &c8;
	
	BTree<int> atree, btree;
	cout<<BTree<int>::likeTree(&c3, &c2);

	return 0;
}

