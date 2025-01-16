#include "..\structures.h"
#include <stdio.h>

int main(){

    Queue* my_queue_ptr = newQueue();
    Node* my_node_ptr = newNode("my key");

    enqueue(my_queue_ptr, my_node_ptr);
    enqueue(my_queue_ptr, newNode("qwerty"));
    dequeue(my_queue_ptr); //returns the "my key" node 
    clearQueue(my_queue_ptr,1,1);
    //first flag deletes the queue from the heap memory.
    //second flag deletes the nodes from the heap memory.

    //for a more specific operation with the entity you can 
    //treat the my_queue_ptr->elements property (it's a list, so you can use list functions)
    
}