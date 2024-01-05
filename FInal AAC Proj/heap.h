#pragma once
#ifndef HEAP_H
#define HEAP_H
#include"lib.h"
#include <iostream>

void heapify(int* Array, int n, int i) {
	int a = 2 * i + 1;
	int b = 2 * i + 2;
	int largest = i;

	if (a< n && Array[a] > Array[i]) {
		largest = a;
	}

	if (b< n && Array[b] > Array[largest]) {
		largest = b;
	}

	if (largest != i) {
		std::swap(Array[i], Array[largest]);
		heapify(Array, n, largest);
	}
}

void buildHeap(int* Array, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(Array, n, i);
}

void heapSort(int* Array, int n) {
	buildHeap(Array, n);
	for (int i = n - 1; i >= 0; i--) {
		std::swap(Array[0], Array[i]);
		heapify(Array, i, 0);
	}
}

#endif//HEAP_H