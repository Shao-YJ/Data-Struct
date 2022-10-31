#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	BinaryTree<int> head(6);
	head.lc = new BinaryTree<int>(2);
	head.rc = new BinaryTree<int>(9);
	//p=head.SearchT(9,t);
	head.insertT(1);
	head.insertT(4);
	head.insertT(8);
	head.deleteT(6);

	return 0;
}

