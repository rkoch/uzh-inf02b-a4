//
//  Heap.cpp
//  Heap
//
//  Created by Loc Nguyen on 21.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#include "Heap.h"
#include <iostream>
#include <vector>

// class constructs

template<typename Key, typename Element>
MyHeap<Key, Element>::MyHeap(int capac)
		: capacity(capac), heap(1, NULL) {          // heap is now a vector, containing NULL at idx 0 - push_back() will insert at index 1
	heap.reserve(capacity);                         // Reserve capacity items in vector
}

template<typename Key, typename Element>
MyHeap<Key, Element>::~MyHeap() {
	for (unsigned i = 0; i < heap.size(); i++) {
		delete heap[i];
	}
	heap.clear();
}

// public methods

template<typename Key, typename Element>
int MyHeap<Key, Element>::size() const {
	return heap.size() - 1;
}

template<typename Key, typename Element>
bool MyHeap<Key, Element>::isEmpty() const {
	return size() <= 0;
}

template<typename Key, typename Element>
const Element& MyHeap<Key, Element>::minElement() const throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = heap[1];                              // Separate pointer for better debugging purposes
	return n->second;
}

template<typename Key, typename Element>
const Key& MyHeap<Key, Element>::minKey() const throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = heap[1];                              // Separate pointer for better debugging purposes
	return n->first;
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::insertItem(const Key& k, const Element& e) {
	heap.push_back(new Node(k, e));

	// Re-balance heap
	decrease(heap.size() - 1);

#ifdef DEBUG
	printHeap();
#endif
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::removeMin() throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = heap[1];                              // Separate pointer for better debugging purposes
	delete n;
	n = NULL;

	heap[1] = heap.back();                          // Put tail of heap to root
	heap.pop_back();                                // And remove it from there

	// Re-balance heap
	heapify(1);

#ifdef DEBUG
	printHeap();
#endif
}

// private methods

template<typename Key, typename Element>
bool MyHeap<Key, Element>::isStorageFull() {
	return heap.size() >= (unsigned) capacity;
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::printHeap() {
	std::cout << "Current heap contents: " << std::flush;
	for (unsigned i = 1; i < heap.size(); i++) {
		std::cout << "(" << heap[i]->first << ", " << heap[i]->second << ") ";
		std::cout << std::flush;
	}
	std::cout << std::endl;
}

// helper methods

template<typename Key, typename Element>
void MyHeap<Key, Element>::swap(int idx1, int idx2) {
	heap[0] = heap[idx1];
	heap[idx1] = heap[idx2];
	heap[idx2] = heap[0];
	heap[0] = NULL;
}

template<typename Key, typename Element>
unsigned MyHeap<Key, Element>::parent(int childIdx) {
	return (int) childIdx / 2;
}

template<typename Key, typename Element>
unsigned MyHeap<Key, Element>::left(int parentIdx) {
	return parentIdx * 2;
}

template<typename Key, typename Element>
unsigned MyHeap<Key, Element>::right(int parentIdx) {
	return (parentIdx * 2) + 1;
}

// heap balancing methods

template<typename Key, typename Element>
void MyHeap<Key, Element>::heapify(int idx) {
	int i = idx;

	while (true) {                                  // Create infinite loop to avoid recursive heapify
		bool leftExists = heap.size() > left(i);
		bool rightExists = heap.size() > right(i);
		int swapIdx = i;

		if (leftExists && (heap[left(i)]->first < heap[swapIdx]->first)) {
			swapIdx = left(i);
		}
		if (rightExists && (heap[right(i)]->first < heap[swapIdx]->first) && heap[right(i)]->first < heap[left(i)]->first) {
			swapIdx = right(i);
		}
		if (swapIdx == i) {
			break;                                  // Nothing needs to be balanced
		}

		swap(i, swapIdx);
		i = swapIdx;
	}
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::decrease(int idx) {
	int i = idx;
	while ((i > 1) && (heap[i]->first < heap[parent(i)]->first)) {
		swap(i, parent(i));
		i = parent(i);
	}
}

// Tell the compiler explicitly which type implementation of the generic MyHeap it should build.
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class MyHeap<int, std::string> ;
