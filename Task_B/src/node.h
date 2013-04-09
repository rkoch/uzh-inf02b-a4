//
//  node.h
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//



#ifndef EulerTour_node_h
#define EulerTour_node_h

#include <vector>
#include <iostream>

using namespace std;
struct edge;


class node {
public:
    node(int id_);
    
    vector<edge*> get_edges();
    void add_edge(node* newNode);
    int get_id();

    
private:
    vector<edge*> _edges;
    int _id;

};

struct edge{
    node* node1;
    node* node2;
    
    bool visited;
    
    edge(){
        visited = false;
    }
    
    node getn1(){
        return *node1;
    }
    
    node getn2(){
        return *node2;
    }
};


#endif
