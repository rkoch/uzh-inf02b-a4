//
//  graph.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#include <iostream>
#include "graph.h"

graph::graph() {

}

void graph::add_node(node* new_node) {
	if (new_node != 0) {
		_nodes.push_back(new_node);
	}
}

vector<node*> graph::get_nodes() {
	return _nodes;
}
