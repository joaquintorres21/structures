#include "structures.h"
#include <stdlib.h>

//INSTANTIATION FUNCTIONS

Node* newNode(int node_value){

    Node* created_node = (Node*) malloc(sizeof(Node));
    if(!created_node) return ERROR;
    created_node -> value = node_value;
    created_node -> next = NULLPTR;
    return created_node;

}

List* newList(Node* init_head){
    
    List* created_list = (List*)malloc(sizeof(List));
    if(!created_list) return ERROR;
    created_list->head = init_head;
    return created_list;

}

Stack* newStack(Node* init_top){
    
    Stack* created_stack = (Stack*)malloc(sizeof(Stack));
    if(!created_stack) return ERROR;
    created_stack->elements->head = init_top;
    return created_stack;
}

//LIST FUNCTIONS

Node* deleteNode(List* list, Node* node_ptr, int free_trigger){
    int deleted = 0;
    Node * current_node = list -> head;
    Node * prev_node = NULLPTR;
    for(int increment = 0; current_node -> next != NULLPTR; increment++){
        
        if(current_node == node_ptr){
            deleted = 0;
            if(!prev_node) {
                list->head = current_node->next;
                break;
            }
            else prev_node -> next = current_node -> next;
            break;
            
        }
        prev_node = current_node;
        current_node = current_node -> next;

    }
    //This for is dependent of the ammount of elements in the list, so the complexity is O(n) for all
    //simple lists.
    if(!deleted) return ERROR;
    //If the object is not found in the list, the function returns a 1 implicitly casted.
    if(free_trigger!=0) {
        free(node_ptr);
        return NULLPTR;
        //The node_ptr is now pointing to a random address and may cause problems, so we just discard it.
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

char insert(List* list, Node* new_node, int position){

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

char stack(Stack * stack, Node * new_node){

    new_node -> next = stack->elements->head;
    stack->elements->head = new_node;
    return 0;
}

Node* unstack(Stack* stack){

    Node* ptr_to_head = stack->elements->head;
    stack->elements->head = stack->elements->head->next;
    return ptr_to_head;
    
}

Stack* clearStack(Stack* stack, int clean_buffer){

    clearList(stack->elements);
    if(clean_buffer){

        free(stack);
        return NULLPTR;
    
    }
    return stack;

}