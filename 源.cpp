#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	int list[11] = {0,10,56,859,12,564,84,98,2463,849,4166}, i;
	int delta[3] = { 5,3,1 };
	SelectSort<int>(list, 10);
	for (i = 1; i <= 10; i++)
		cout << list[i] << " ";

	return 0;
}

