//
//  graph.h
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
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
