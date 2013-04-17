//
//  main.cpp
//  Heap
//
//  Created by Loc Nguyen on 20.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#include "Heap.h"
#include <iostream>

std::string chelsea[11] = { "Cech", "Cole", "Luiz", "Essien", "Ramires", "Lampard", "Torres", "Drogba", "Mata", "Malouda", "Bosingwa" };

int main(int argc, const char * argv[]) {
	MyHeap<int, std::string> heap;
	try {

		//heap.removeMin();
		//heap.minElement();
		heap.insertItem(1, "Cech");
		std::cout << "Heap size after adding Cech: \n" << heap.size() << std::endl;

		heap.insertItem(7, "Ramires");
		heap.insertItem(9, "Torres");
		heap.insertItem(11, "Drogba");
		std::cout << "Heap size after adding Ramires, Torres, Drogba: \n" << heap.size() << std::endl;
		std::cout << "Min key and element is: \n" << heap.minKey() << " " << heap.minElement() << std::endl;

		heap.removeMin();
		std::cout << "Heap size after remove min-element: \n" << heap.size() << std::endl;
		std::cout << "New minkey and minelement \n" << heap.minKey() << " " << heap.minElement() << std::endl;

		heap.insertItem(3, "Cole");
		heap.insertItem(5, "Essien");
		std::cout << "Heap size after adding Cole & Essien: \n" << heap.size() << std::endl;
		std::cout << "New minkey and minelement \n" << heap.minKey() << " " << heap.minElement() << std::endl;

		std::cout << std::endl << "Priority queue order: " << std::endl;
		while (!heap.isEmpty()) {
			std::cout << heap.minKey() << " " << heap.minElement() << std::endl;
			heap.removeMin();
		}

	} catch (EmptyContainerException& e) {
		std::cout << e.what();
	}

	return 0;
}

