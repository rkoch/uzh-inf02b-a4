//
//  graph.h
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#ifndef EulerTour_graph_h
#define EulerTour_graph_h

#include <vector>
#include "node.h"

using namespace std;

class graph {

public:
	graph();

	void add_node(node* new_node);
	vector<node*> get_nodes();

private:
	vector<node*> _nodes;

};

#endif
