#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	Edge edge[20];
	char list[8] = { 'a','b','c','d','e','f','g','h' };
	MatrixGraph<char> graph(1);
	graph.setVe(list,8);
	graph.create();
	graph.toString();
	graph.edges(edge);
	graph.Dijkstra(0);


	//ListGraph<char> lgraph(list,8,1);
	//lgraph.create();
	//lgraph.toString();
	//lgraph.Dijkstra(0);

	

	return 0;
}

