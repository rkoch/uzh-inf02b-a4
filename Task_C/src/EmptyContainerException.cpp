/*
 * EmptyContainerException.cpp
 *
 * Created on: 09.04.2013
 *
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a4
 */

#include "EmptyContainerException.h"

const char* EmptyContainerException::what() const throw () {
	return "Error: Heap is empty.";
}
