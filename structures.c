#include "structures.h"

Node* last(List* list){

    Node * current_node = list -> head;
    for(int increment = 0; current_node -> next != 0; increment++){

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
            return 0;

        }
        current_node = current_node -> next;
    
    }
    current_node -> next = new_node;
    return 0;

}

Node* deleteNode(List* list, Node* node_ptr){

    Node * current_node = list -> head;
    for(int increment = 0; current_node -> next != 0; increment++){
        
        if(current_node -> next == node_ptr){

            current_node -> next = node_ptr -> next;

        }
        current_node = current_node -> next;

    }
    return node_ptr;
}