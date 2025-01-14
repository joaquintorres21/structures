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

Queue* newQueue(Node* init_first){
    
    Queue* created_queue = (Queue*)malloc(sizeof(Queue));
    if(!created_queue) return ERROR;
    created_queue->elements->head = init_first;

}

Stack* newStack(Node* init_top){
    
    Stack* created_stack = (Stack*)malloc(sizeof(Stack));
    if(!created_stack) return ERROR;
    created_stack->elements->head = init_top;
    return created_stack;

}

//LIST FUNCTIONS

Node* deleteNode(List* list, Node* node_ptr, int free_trigger){
    Node* current_node = list->head;
    while(current_node->next!=node_ptr){

        if(!current_node->next) return NULLPTR;
        //If there is no such node the function returns an exception.
        current_node = current_node->next;

    }
    current_node->next = current_node->next->next;
    if(free_trigger){
        
        free(node_ptr);
        return NULLPTR;

    }
    return node_ptr;

}

List* clearList(List* reference, int clear_buffer){
    
    if(clear_buffer) {
        
        free(reference);
        return NULLPTR;

    }
    
    reference->head = NULLPTR;
    return reference;

}

Node* last(List* list){

    Node * current_node = list -> head;
    while(current_node->next){

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

//QUEUE FUNCTIONS

//ENQUEUE, DEQUEUE, CLEARQUEUE
char enqueue(Queue* queue_ptr, Node* node_ptr){
    


}

Node* dequeue(Queue* queue_ptr){

    
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

Node* top(Stack* stack){

    if(!stack->elements->head) return NULLPTR;
    return stack->elements->head;

}

Node* bottom(Stack* stack){

    if(!stack->elements->head) return NULLPTR;
    return last(stack->elements);

}

Stack* clearStack(Stack* stack, int clear_buffer){

    clearList(stack->elements, clear_buffer);
    if(clear_buffer){

        free(stack);
        return NULLPTR;
    
    }
    return stack;

}