#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	CSnode<int> tree(0);

	CSnode<int> l1_1(11), l1_2(12), l1_3(13), l1_3_lc(131);
	CSnode<int> l2_1(21), l2_2(22);
	CSnode<int> l3_1(31);

	tree.Child1 = &l1_1; l1_1.Sibling = &l1_2; l1_2.Sibling = &l1_3; l1_3.Child1 = &l1_3_lc;
	l1_1.Child1 = &l2_1; l2_1.Sibling = &l2_2; l2_1.Child1 = &l3_1;
	//tree.init();
	CSnode<int>::levelTree(tree);
	
	return 0;
}

