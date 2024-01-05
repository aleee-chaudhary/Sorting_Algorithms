#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include "lib.h"
#include "insert.h"
#include "radix.h"
#include "heap.h"
#include "quick.h"

using std::chrono::nanoseconds;

nanoseconds measure(int* Original_Array, int* Array, int size, void func(int*, int)) {
	std::copy(Original_Array, Original_Array + size, Array);

	auto begin = std::chrono::steady_clock::now();
	func(Array, size);
	auto end = std::chrono::steady_clock::now();

	assert(std::is_sorted(Array, Array + size));

	nanoseconds final(end - begin);
	return final;
}

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	int times = 100;

	std::cout << "size  Insertion_Sort  Quick_Sort  Radix_Sort  Heap_Sort" << std::endl;

	for (int size = 100; size <= 10000; size += 100) {
		nanoseconds insert(0);
		nanoseconds quick(0);
		nanoseconds radix(0);
		nanoseconds heap(0);

		int* Original_Array = new int[size];
		int* Array = new int[size];
		int* sorted = new int[size];

		for (int i = 0; i < size; i++) {
			Original_Array[i] = i;
		}

		for (int t = 0; t < times; t++) {
			std::shuffle(Original_Array, Original_Array + size, gen);

			insert += measure(Original_Array, Array, size, &insertionSort);
			quick += measure(Original_Array, Array, size, &quickSort);
			radix += measure(Original_Array, Array, size, &radixSort);
			heap += measure(Original_Array, Array, size, &heapSort);
		}

		std::cout
			<< size << " " << insert.count() / times << " " << quick.count() / times << " "
			<< radix.count() / times << " " << heap.count() / times << std::endl;

		delete[] Array;
		delete[] sorted;
		delete[] Original_Array;
	}
	return 0;
}