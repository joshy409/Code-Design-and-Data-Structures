#include "tVector.h"
#include <iostream>
#include <vector>
int main() {
	tVector<int> test;
	
	for (int i = 0; i < 50; i++) {
		test.push_back(i*2);
	}

	for (int i = 0; i < test.size(); i++) {
		std::cout << test.at(i) << std::endl;
	}
}