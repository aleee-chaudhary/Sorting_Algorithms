#pragma once
#include <iostream>
#ifndef LIB_H
#define LIB_H

void print(int* Array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << Array[i] << " ";
	}
	std::cout << std::endl;
}

#endif // LIB_H
