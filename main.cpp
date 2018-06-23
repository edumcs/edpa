#include <iostream>
#include "heapTree.h"

using namespace std;

int main(int argc, char** argv) {
	//int a[] = {4,5,2,3,6,7};
	
	Heap<int> heap;
	
	heap.inserir(2);

  	cout << "Valor: " << heap.no->valor;
		
		
  	return 0;
}
