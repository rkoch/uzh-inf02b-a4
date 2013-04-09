//
//  Heap.h
//  Heap
//
//  Created by Loc Nguyen on 20.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>

#include "Exception.h"

using std::vector;
using std::pair;
using std::string;

// You need to put the following methods inside your Heap class definition

MyHeap(int capac = 100);		// constructor
int size() const;						// number of elements
bool isEmpty() const;					// is the queue empty?
    
const string& minElement() const throw(EmptyContainerException) ;	// return min element
const int& minKey() const throw(EmptyContainerException) ;	// return minimum key
    
void insertItem(const Key& k, const Element& e);				// insert (key, element)
void removeMin() throw(EmptyContainerException);				// remove minimum
    

#endif
