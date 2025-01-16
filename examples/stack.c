#include "..\structures.h"
#include <stdio.h>

int main(){

    Stack* my_stack_ptr = newStack();
    Node* my_node_ptr = newNode("my key");

    stack(my_stack_ptr, my_node_ptr);
    stack(my_stack_ptr, newNode("qwerty"));
    unstack(my_stack_ptr); //returns the "qwerty" node 
    clearStack(my_stack_ptr,1,1);
    //first flag deletes the stack from the heap memory.
    //second flag deletes the nodes from the heap memory.

    //for a more specific operation with the entity you can 
    //treat the my_stack_ptr->elements property (it's a list, so you can use list functions)
}