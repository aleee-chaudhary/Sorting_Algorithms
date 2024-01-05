#pragma once
#ifndef QUICK_H
#define QUICK_H
#include "lib.h"
#include <algorithm>

int partition(int* Array, int low, int high) {
	int pivot = Array[low];
	int i = (high + 1);

	for (int j = high; j > low; j--) {
		if (Array[j] > pivot) {
			i--;
			std::swap(Array[i], Array[j]);
		}
	}
	std::swap(Array[i - 1], Array[low]);
	return i - 1;
}

void quickSort(int* Array, int low, int high) {
	if (low < high) {
		int pivot_pos = partition(Array, low, high);
		quickSort(Array, low, pivot_pos - 1);
		quickSort(Array, pivot_pos + 1, high);
	}
}

void quickSort(int* Array, int size) {
	quickSort(Array, 0, size - 1);
}

#endif  // QUICK_H
