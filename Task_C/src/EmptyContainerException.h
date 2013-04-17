/*
 * EmptyContainerException.h
 *
 * Created on: 09.04.2013
 *
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a4
 */

#ifndef EMPTYCONTAINEREXCEPTION_H_
#define EMPTYCONTAINEREXCEPTION_H_

#include <exception>

class EmptyContainerException: public std::exception {

public:

	virtual const char* what() const throw ();

};

#endif /* EMPTYCONTAINEREXCEPTION_H_ */
