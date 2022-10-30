#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	//Edge edge[20];
	char list[8] = { 'a','b','c','d','e','f','g','h' };
	//MatrixGraph<char> graph(0);
	//graph.setVe(list,6);
	//graph.create();
	//graph.toString();
	//graph.TopoSort();


	ListGraph<char> lgraph(list,6,0);
	lgraph.create();
	lgraph.toString();
	lgraph.TopoSort();

	

	return 0;
}

