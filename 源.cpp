#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	char list[8] = { 'a','b','c','d','e','f','g','h' };
	MatrixGraph<char> graph;
	graph.setVe(list,8);
	graph.create();
	graph.toString();
	graph.setVisited();
	//graph.DFSTraverse(7);
	cout << endl << endl;

	ListGraph<char> lgraph(list,8,1);
	lgraph.create();
	lgraph.toString();
	lgraph.setVisited();
	//lgraph.DFSTraverse(7);

	return 0;
}

