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

// class constructs

template<typename Key, typename Element>
MyHeap<Key, Element>::MyHeap(int capac)
		: capacity(capac), count(0) {
	increaseStorage();
}

template<typename Key, typename Element>
MyHeap<Key, Element>::~MyHeap() {
	if (nodes != NULL) {
		delete[] nodes;
		nodes = NULL;
	}
}

// public methods

template<typename Key, typename Element>
int MyHeap<Key, Element>::size() const {
	return count;
}

template<typename Key, typename Element>
bool MyHeap<Key, Element>::isEmpty() const {
	return count <= 0;
}

template<typename Key, typename Element>
const Element& MyHeap<Key, Element>::minElement() const throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = nodes[1];          			 // Separate pointer for better debugging purposes
	return n->second;
}

template<typename Key, typename Element>
const Key& MyHeap<Key, Element>::minKey() const throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = nodes[1];         			 // Separate pointer for better debugging purposes
	return n->first;
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::insertItem(const Key& k, const Element& e) {
	if (isStorageFull()) {
		increaseStorage();
	}

	// Get first free index
	int idx;
	for (idx = 1; idx < capacity; idx++) {
		if (nodes[idx] == NULL) {
			break;
		}
	}

	nodes[idx] = new Node(k, e);
	count++;

	// Re-balance heap
	balanceHeap();
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::removeMin() throw (EmptyContainerException) {
	if (isEmpty()) {
		throw EmptyContainerException();
	}

	Node* n = nodes[1];         			 // Separate pointer for better debugging purposes
	nodes[1] = NULL;
	delete n;
	count--;

	// Re-balance heap
	balanceHeap();
}

// private methods

template<typename Key, typename Element>
bool MyHeap<Key, Element>::isStorageFull() {
	return (capacity - 1) <= count;          // -1 because first element can never be used
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::increaseStorage() {
	int oldCap = capacity;
	NodePtr* oldNo = nodes;

	if (oldNo != NULL) {
		capacity *= 2;
	}

	nodes = new NodePtr[capacity];

	if (oldNo != NULL) {
		// copy all to new and delete the old one
		for (int i = 0; i < oldCap; i++) {
			nodes[i] = oldNo[i];
		}
		// delete[] oldNo; -> No deletion because the Node (pair) pointers will be reused
		oldNo = NULL;
	}
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::balanceHeap() {
	// TODO stuff
}

// Tell the compiler explicitly which type implementation of the generic MyHeap it should build.
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class MyHeap<int, std::string> ;
