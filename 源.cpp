#include"std.h"
#include"Test.h"
#include"Tree/Huffman.h"

int main() {

	int list[11] = {0,100,56,859,12,564,84,98,2463,849,4166};
	int countlist[9] = {0,5,2,3,7,4,3,5,6};
	int delta[3] = { 5,3,1 };
	//TreeSort<int>(list,10);

	RadixNode<int>* L, * p;
	L = new RadixNode<int>(0, 0);
	for (int i = 10; i >0; i--) {
		p = new RadixNode<int>(list[i], list[i]);
		p->next = L->next;
		L->next = p;
	}
	RadixSort<int>(L, 10);
	//for (i = 1; i <= 10; i++)
	//	cout << list[i] << " ";
	return 0;
}

