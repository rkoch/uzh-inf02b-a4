//
//  node.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#include <iostream>
#include "node.h"

node::node(int id_)
		: _id(id_) {

}

vector<edge*> node::get_edges() {
	return _edges;
}

/*
 * 1) add a new edge between this node and newNode
 */
void node::add_edge(node* newNode) {
	edge* e = new edge();
	e->node1 = this;
	e->node2 = newNode;
	_edges.push_back(e);

}

int node::get_id() {
	return _id;
}
