#include "structures.h"
#include <stdlib.h>

Node* newNode(int node_value){

    Node* created_node = (Node*) malloc(sizeof(Node));
    created_node -> value = node_value;
    created_node -> next = NULLPTR;
    return created_node;

}

Node* deleteNode(List* list, Node* node_ptr, int free_trigger){

    Node * current_node = list -> head;
    for(int increment = 0; current_node -> next != NULLPTR; increment++){
        
        if(current_node -> next == node_ptr){

            current_node -> next = node_ptr -> next;

        }
        current_node = current_node -> next;

    
    }
    if(free_trigger) {
        free(node_ptr);
        return NULLPTR;
        //The node_ptr is now useless and may cause problems, so we just discard it.
    }
    return node_ptr;
}

List* clearList(List* reference){
    
    reference->head = NULLPTR;
    return reference;

}

Node* last(List* list){

    Node * current_node = list -> head;
    for(int increment = 0; current_node -> next != NULLPTR; increment++){

            current_node = current_node -> next;

    }
    return current_node;

}

char append(List* list, Node* new_node){

    Node * ptr_to_end = last(list);
    ptr_to_end -> next = new_node;
    return SUCCESS;

}

char unshift(List* list, Node* new_node){

    new_node -> next = list -> head;
    list -> head = new_node;
    return SUCCESS;

}

char index(List* list, Node* new_node, int position){

    Node * current_node = list -> head;
    for(int increment = 0; increment < position; increment++){
        
        if(!current_node -> next){
            
            current_node -> next = new_node;
            return SUCCESS;

        }
        current_node = current_node -> next;
    
    }
    new_node -> next = current_node -> next;
    current_node -> next = new_node;
    return SUCCESS;

}

//STACK FUNCTIONS

STACK char stack(Stack * stack, Node * new_node){

    new_node -> next = stack->elements->head;
    stack->elements->head = new_node;

}

STACK Node* unstack(Stack* stack){

    Node* ptr_to_head = stack->elements->head;
    stack->elements->head = stack->elements->head->next;
    return ptr_to_head;
    
}