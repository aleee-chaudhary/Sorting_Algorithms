#pragma once
#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
#include "lib.h"

int MaxElement(int* Array, int n) {
	int max = Array[0];

	for (int i = 0; i < n; i++) {
		if (Array[i] > max) {
			max = Array[i];
		}
	}
	return max;
}

void count(int* Array, int n, int counting) {
	int* temp = new int[n];
	int count_Array[10] = { 0 };

	for (int i = 0; i < n; i++) {
		count_Array[(Array[i] / counting) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		count_Array[i] += count_Array[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		temp[count_Array[(Array[i] / counting) % 10] - 1] = Array[i];
		count_Array[(Array[i] / counting) % 10]--;
	}

	for (int i = 0; i < n; i++) {
		Array[i] = temp[i];
	}
	delete[] temp;
}

void radixSort(int* Array, int n) {
	int max = MaxElement(Array, n);

	for (int counting = 1; max / counting > 0; counting *= 10) {
		count(Array, n, counting);
	}
}
#endif // !RADIXSORT_H
