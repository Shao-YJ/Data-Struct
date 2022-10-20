#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	Graph<char> graph;
	char list[6] = { 'a','b','c','d','e','f' };
	graph.setVe(list, 6);
	graph.create();
	graph.toString();


	return 0;
}

