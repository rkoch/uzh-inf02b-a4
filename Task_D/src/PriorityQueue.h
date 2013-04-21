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

#ifndef heaps_priority_queues_PriorityQueue_h
#define heaps_priority_queues_PriorityQueue_h

#include <vector>

class PriorityQueue {

private:
	std::vector<int> queue;

public:

	PriorityQueue();

	int getFrontElement();

	void insert(int _element);

	void remove();

	void heapsort();

	void printQueue();

};

#endif
