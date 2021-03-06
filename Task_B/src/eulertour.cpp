//
//  eulertour.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a4
//

#include "graph.h"
#include <iostream>

using namespace std;

void print_graph(graph* newGraph);
int eulertour(graph* eulergraph);
void createCircle(graph* myGraph);

static int MAX_NODES = 5;

int main() {
	graph myGraph;

	// create Nodes and add them to the graph
	for (int i = 0; i < MAX_NODES; i++) {
		node* temp = new node(i);
		myGraph.add_node(temp);
	}

	// creates edges between nodes
	createCircle(&myGraph);

	print_graph(&myGraph);

	int result = eulertour(&myGraph);

	if (result > 0) {
		cout << "Euler path found" << endl;
	} else {
		cout << "no euler" << endl;
	}

	return 0;
}

/* 2) complete the funciton so it prints a small overview of the graph
 *    Example:
 *
 *    Edges Node 0
 *    0---1
 *
 *    Edges Node 1
 *    1---3
 */
void print_graph(graph* newGraph) {
	std::vector<node*>::const_iterator it_node;
	std::vector<edge*>::const_iterator it_edge;
	for (unsigned i = 0; i < newGraph->get_nodes().size(); i++) {
		std::cout << "Edges Node " << newGraph->get_nodes().at(i)->get_id() << std::endl;
		for (unsigned j = 0; j < newGraph->get_nodes().at(i)->get_edges().size(); j++) {
			std::cout << newGraph->get_nodes().at(i)->get_edges().at(j)->node1->get_id() << "---" << newGraph->get_nodes().at(i)->get_edges().at(j)->node2->get_id() << std::endl;
		}
		std::cout << std::endl;
	}
}

void createCircle(graph* myGraph) {
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

/*
 * 3) complete the function so it returns 1 if the given graph has an eulerpath and -1 if it hasn't.
 */
int eulertour(graph* eulergraph) {
	std::vector<int> edgeCount(eulergraph->get_nodes().size(), 0);
	for (unsigned i = 0; i < eulergraph->get_nodes().size(); i++) {
		for (unsigned j = 0; j < eulergraph->get_nodes().at(i)->get_edges().size(); j++) {
			edgeCount[eulergraph->get_nodes().at(i)->get_edges().at(j)->node1->get_id()]++;
			edgeCount[eulergraph->get_nodes().at(i)->get_edges().at(j)->node2->get_id()]++;
		}
	}
	int oddCount = 0;
	for (unsigned k = 0; k < edgeCount.size(); k++) {
		if (edgeCount[k] % 2 != 0)
			oddCount++;
	}

	if (oddCount > 2)
		return -1;
	else
		return 1;
}
