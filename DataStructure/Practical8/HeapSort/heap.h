/*
 * heap.h
 *
 *  Created on: 10 May 2019
 *      Author: dongmo
 */

#ifndef HEAP_H_
#define HEAP_H_

class HeapType {
	int maxHeapSize;
	int* list;
	int size;
public:
	HeapType(int ms) {
		if (ms < 0)
			ms = 10;
		maxHeapSize = ms;
		list = new int[maxHeapSize];
		size = 0;
	}

	HeapType(int l[], int s, int ms) {
		if (ms < 0)
			ms = 10;
		maxHeapSize = ms;
		size = s;
		list = new int[maxHeapSize];

		for(int i=0;i<maxHeapSize;i++) {
			list[i] = l[i];
		}
	}

	~HeapType() {
		delete[] list;
	}

	void reheapUp(int);
	void reheapDown(int, int);
	void swap(int, int);
	void printHeap();
};

void HeapType::reheapUp(int heapLast) {
	int parent;
	int child;

	if (heapLast != 0) {
		parent = (heapLast - 1) / 2;
		child = heapLast;
		if (list[child] > list[parent]) {
			swap(child, parent);
			reheapUp(parent);
		}
	}
	return;
}	// reheapUp


void HeapType::reheapDown(int current, int heapLast) {
	int parent;
	int lftChild;
	int rgtChild;
	int maxChild;

	parent = current;
	lftChild = (current * 2) + 1;
	rgtChild = lftChild + 1;

	if (lftChild <= heapLast) {
		if (lftChild == heapLast)
			maxChild = lftChild;
		else
		if (list[lftChild] > list[rgtChild])
			maxChild = lftChild;
		else
			maxChild = rgtChild;

		if (list[parent] < list[maxChild]) {
			swap(parent, maxChild);
			reheapDown(maxChild, heapLast);
		}  else
			return;
	}

	return;
}	// reheapDown

void HeapType::swap(int x1, int x2) {

	int temp = list[x1];
	list[x1] = list[x2];
	list[x2] = temp;

	return;
}	// swap

void HeapType::printHeap() {
	for (int i = 0; i < size; i++)
	    cout << setw(3) <<  list[ i ];
	cout << endl ;
	return;
}

#endif /* HEAP_H_ */
