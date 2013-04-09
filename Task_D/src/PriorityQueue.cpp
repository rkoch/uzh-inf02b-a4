/*
 Assignment 4 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */

#include <iostream>
#include "PriorityQueue.h"


//MISSING INCLUDE!! find the library to include...


PriorityQueue::PriorityQueue(){
    
    //create queue and fill it with starting elements
    queue.push_back(99);
    queue.push_back(3);
    queue.push_back(45);
    queue.push_back(2);
    queue.push_back(13);
    
    
    std::make_heap(queue.begin(), queue.end());   // build heap order on the queue, so that greatest element is on top
    
    
}





int PriorityQueue::getFrontElement(){  //return the topelement
    
    return queue.at(0);
    
}



void PriorityQueue::insert(int _element){
    

    //TODO: insert code here
}


void PriorityQueue::remove(){
    
    //TODO: insert code here
}


void PriorityQueue::heapsort(){
    //TODO: insert code here    
}

void PriorityQueue::printQueue(){
    std::cout << "Current Queue: " << std::endl;
    
   
    //TODO: insert code here
    
    
    std::cout << std::endl;
}


