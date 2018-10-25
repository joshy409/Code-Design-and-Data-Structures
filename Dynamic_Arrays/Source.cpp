#include "tVector.h"
#include <iostream>
#include <vector>
int main() {
	tVector<int> test;
	
	for (int i = 0; i < 5; i++) {
		test.push_back(i);
	}

	tVector<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);

	
	tVector<int> copy = original;
	original.pop_back(); // removes from the original array, but not the copy
	original.pop_back();
	original.pop_back();

	std::cout << "copy" << std::endl;
	copy.print();

	original.push_back(9);
	original.push_back(10);
	original.push_back(11);
	original.push_back(11);

	original[0] = 15;



	copy = original;

	std::cout << "original" << std::endl;
	original.print();
	original.pop_back(); // removes from the original array, but not the copy
	original.pop_back();
	original.pop_back();

	std::cout << "copy" << std::endl;
	copy.print();

	copy.clear();
	if (!copy.empty()) {
		
		std::cout << "copy" << std::endl;
		std::cout << copy.capacity() << std::endl;
		copy.print();
	}
	else {
		std::cout << "no element" << std::endl;
	}

	copy.push_back(10);

	copy.push_back(10);
	copy.resize(20);
	copy.print();
	std::cout << copy.size() << std::endl;
	std::cout << copy.capacity() << std::endl;

}