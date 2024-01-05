#pragma once
#ifndef INSERT_H
#define INSERT_H
#include "lib.h"

void insertionSort(int* Array, int n) {
	for (int i = 1; i < n; i++) {
		int temp_arr = Array[i];
		int j = i - 1;

		while (temp_arr < Array[j] && j >= 0) {
			Array[j + 1] = Array[j];
			--j;
		}
		Array[j + 1] = temp_arr;
	}
}
#endif  // INSERT_H
