/*
 Assignment 4 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */

#include <iostream>
#include "PriorityQueue.h"


int main (int argc, const char * argv[])
{


    
   
    
    
    /* INTRODUCTION:
     Check out the following links for further information on how to work with heap-functions on vectors:
     
     
      [1]  http://www.cplusplus.com/reference/algorithm/make_heap/
      [2]  http://www.cplusplus.com/reference/algorithm/push_heap/
      [3]  http://www.cplusplus.com/reference/algorithm/pop_heap/
      [4]  http://www.cplusplus.com/reference/algorithm/sort_heap/
     
     
     
     Implement your solution based on the instructions and infos you find on the given links!
     */
    
    
    //create priority queue
    //elements with highest priority should always be on top
    PriorityQueue my_p_queue = PriorityQueue();
    
    

    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.insert(120);
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.remove();
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.insert(450);
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.insert(999);
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.remove();
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.remove();
    
    std::cout << "TOP element:  " << my_p_queue.getFrontElement() << std::endl;
    my_p_queue.printQueue();
    my_p_queue.heapsort();
    
    my_p_queue.printQueue();
    
    return 0;
}

