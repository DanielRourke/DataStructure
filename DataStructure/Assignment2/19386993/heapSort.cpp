#include <iostream>
#include <iomanip>

using namespace std;

#include"heap.h"

const int MAXSIZE = 100;

void heapSort(int list[], int size) {
	HeapType heap(list, size, MAXSIZE);

	cout << "Unsorted array: ";
	heap.printHeap();

	// Create heap 
	int sorted;

	for (int walker = 1; walker < size; walker++)
		heap.reheapUp(walker);

//	Heap created. Now sort it. 
	sorted = size - 1;
	while (sorted > 0) {
		heap.swap(0, sorted);
		sorted--;
		heap.reheapDown(0, sorted);
	} // while

	cout << "\nSorted array:   ";
	heap.printHeap();

	return;
}	// heapSort 

int main(void) {
	int ary[15] = { 89, 72, 3, 15, 21, 57, 61, 44, 19, 98, 5, 77, 39, 59, 61 };

	heapSort(ary, 15);
}	// main
