#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	char list[8] = { 'a','b','c','d','e','f','g','h' };
	//MatrixGraph<char> graph(0);
	//graph.setVe(list,8);
	//graph.create();
	//graph.toString();
	//graph.setVisited();

	////for (int i = 0; i < 8; i++) {
	//graph.BFSTraverse(7);
	////	cout << endl;
	////}
	//
	//cout << endl << endl;

	ListGraph<char> lgraph(list,8,1);
	lgraph.create();
	lgraph.toString();
	lgraph.setVisited();
	lgraph.BFSTraverse(1);

	return 0;
}

