/*
 * Assignment 4 - Algorithms and data structures
 *
 * University of Zurich
 * Department of Informatics
 * Vizualization and Multimedia Laboratory
 *
 * Author: Genc Mazlami
 *
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a4
 */

#include "PriorityQueue.h"
#include <iostream>
#include <algorithm>
#include <cmath>
PriorityQueue::PriorityQueue() {
	//create queue and fill it with starting elements
	queue.push_back(99);
	queue.push_back(3);
	queue.push_back(45);
	queue.push_back(2);
	queue.push_back(13);

	std::make_heap(queue.begin(), queue.end());          // build heap order on the queue, so that greatest element is on top
}

int PriorityQueue::getFrontElement() {          //return the topelement
	return queue.at(0);
}

void PriorityQueue::insert(int _element) {
	queue.push_back(_element);
	std::push_heap(queue.begin(), queue.end());
}

void PriorityQueue::remove() {
	std::pop_heap(queue.begin(), queue.end());
	queue.pop_back();
}

void PriorityQueue::heapsort() {
	std::sort_heap(queue.begin(), queue.end());
}

void PriorityQueue::printQueue() {
	std::cout << "Current Queue: " << std::endl;

	for (unsigned i = 0; i < queue.size(); i++) {
		std::cout << queue[i] << ' ' << std::flush;
	}

	std::cout << std::endl;
}
