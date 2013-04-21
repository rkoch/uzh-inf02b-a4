//
//  Heap.h
//  Heap
//
//  Created by Loc Nguyen on 20.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>

#include "EmptyContainerException.h"

using std::vector;
using std::pair;
using std::string;

template<typename Key, typename Element>
class MyHeap {

public:
	typedef pair<Key, Element> Node;

	MyHeap(int capac = 100);          // constructor
	~MyHeap();						// destructor

	int size() const;						// number of elements
	bool isEmpty() const;					// is the queue empty?

	const Element& minElement() const throw (EmptyContainerException);          // return min element
	const Key& minKey() const throw (EmptyContainerException);          // return minimum key

	void insertItem(const Key& k, const Element& e);				// insert (key, element)
	void removeMin() throw (EmptyContainerException);				// remove minimum

private:
	int capacity;
	vector<Node*> heap;

	bool isStorageFull();
	void printHeap();

	void swap(int idx1, int indx2);

	unsigned parent(int childIdx);
	unsigned left(int parentIdx);
	unsigned right(int parentIdx);

	void heapify(int idx);
	void decrease(int idx);

};

#endif
