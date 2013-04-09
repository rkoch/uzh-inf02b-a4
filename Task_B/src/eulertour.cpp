//
//  eulertour.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//

#include "graph.h"
#include <iostream>

using namespace std;

void print_graph(graph* newGraph);
int eulertour(graph* eulergraph);
void createCircle(graph* myGraph);

static int MAX_NODES = 5;


int main(){
    
    graph myGraph;
    
    // create Nodes and add them to the graph
    for(int i=0; i<MAX_NODES; i++){
        node* temp = new node(i);
        myGraph.add_node(temp);
    }
                
    // creates edges between nodes
    createCircle(&myGraph);
    
    print_graph(&myGraph);
    
    int result = eulertour(&myGraph);
    
    if(result > 0){
        cout<<"Euler path found"<<endl;
    }
    else {
        cout<<"no euler"<<endl;
    }
    
    return 0;
}

void print_graph(graph* newGraph){
    /*TODO 2)
     *
     * complete the funciton so it prints a small overview of the graph
     *
     * Example:
     *
     * Edges Node 0
     * 0---1
     *
     * Edges Node 1
     * 1---3
     *
     *
     *
     * write your implementation here
     */
    

}

void createCircle(graph* myGraph){
    node* temp1 = myGraph->get_nodes().at(0);
    node* temp2 = myGraph->get_nodes().at(1);
    myGraph->get_nodes().at(0)->add_edge(temp2);

    
    temp1 = myGraph->get_nodes().at(1);
    temp2 = myGraph->get_nodes().at(2);
    myGraph->get_nodes().at(1)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(2);
    temp2 = myGraph->get_nodes().at(3);
    myGraph->get_nodes().at(2)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(3);
    temp2 = myGraph->get_nodes().at(4);
    myGraph->get_nodes().at(3)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(0);
    temp2 = myGraph->get_nodes().at(4);
    myGraph->get_nodes().at(4)->add_edge(temp1);
}

int eulertour(graph* eulergraph){
    /*TODO 3)
     *
     * complete the function so it returns 1 if the given graph has an eulerpath and -1 if it hasn't.
     *
     * write your implementation here
     */
    
    
    return 1;
}



