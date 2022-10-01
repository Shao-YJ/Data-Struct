#include"std.h"

int main() {

	TMatrix<int> matrix(100, 100,0);
	
	matrix.push(Triple<int>(1, 32, 231));
	matrix.push(Triple<int>(4, 2, 231));
	matrix.push(Triple<int>(5, 1, 231));
	matrix.push(Triple<int>(12, 3, 231));
	matrix.toString();
	return 0;
}