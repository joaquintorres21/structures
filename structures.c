#include "structures.h"
#include <stdlib.h>

//MISC.

int val(Node* node_ptr){

    return node_ptr->value;

}

int next(Node* node_ptr){

    return node_ptr->next;

}

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

BST* newBST(int root_value){

    BST* created_bst = (BST*)malloc(sizeof(BST*));
    if(!created_bst) return ERROR;
    created_bst->value = root_value;
    created_bst->left_child = NULLPTR;
    created_bst->right_child = NULLPTR;
    return created_bst;
}

//LIST FUNCTIONS

Node* deleteNode(List* list, Node* node_ptr, int free_trigger){
    int head_flag = 0; 
    Node* current_node = list->head;
    if(current_node==node_ptr) head_flag++;
    while(current_node->next!=node_ptr && !head_flag){

        if(!current_node->next) return NULLPTR;
        //If there is no such node the function returns an exception.
        current_node = current_node->next;

    }
    if(head_flag) list->head = current_node->next;
    else current_node->next = current_node->next->next;
    if(free_trigger){
        
        free(node_ptr);
        return NULLPTR;

    }
    return node_ptr;

}

Node* deleteVal(List* list, int value, int clear_buffer){

    deleteNode(list, searchNode(list, value), clear_buffer);

}

Node* deletePosition(List* list, int position, int clear_buffer){
   
    deleteNode(list, local(list, position), clear_buffer);

}



List* clearList(List* reference, int clear_buffer, int clear_elements_buffer){
    
    Node*current = reference->head;
    if(clear_elements_buffer){
        
        while(current->next){
            
            deleteNode(reference, current, 1);
            current = current -> next;

        }
        deleteNode(reference, current, 1);
        
    }
    if(clear_buffer) {
        
        free(reference);
        return NULLPTR;

    }
    
    reference->head = NULLPTR;
    return reference;

}

Node* first(List* list){

    return list->head;
    
}

Node* last(List* list){

    Node * current_node = list -> head;
    if(!current_node) return NULLPTR;
    while(current_node->next){

            current_node = current_node -> next;

    }
    return current_node;

}

Node* searchNode(List* list, int val){
    
    Node* current_node = list->head;
    while(current_node){
    
        if(current_node->value == val){
        
            return current_node;
        
        }
        current_node = current_node->next;
    }
    return NULLPTR;

}

Node* local(List* list, int position){

    int increment = 0;
    Node* current_node = list->head;
    while(increment < position){
        
        if(!current_node->next) return NULLPTR;
        current_node = current_node -> next;
        increment++;

    }
    return current_node; 
    
}


char append(List* list, Node* new_node){

    Node * ptr_to_end = last(list);
    if(!ptr_to_end) list->head = new_node;
    else ptr_to_end -> next = new_node;
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

Queue* clearQueue(Queue* queue, int clear_buffer, int clear_elements_buffer){
    
    clearList(queue->elements, clear_buffer, clear_elements_buffer);
    if(clear_buffer){

        free(queue);
        return NULLPTR;
    
    }
    queue->last = NULLPTR;
    return queue;
}

char enqueue(Queue* queue_ptr, Node* node_ptr){
    
    if(!queue_ptr->last){

        append(queue_ptr->elements, node_ptr);
        //appending will not affect since there are no elements, iterating would be O(1)
        queue_ptr->last = node_ptr;
        return SUCCESS;

    }
    queue_ptr->last->next = node_ptr;
    queue_ptr->last = node_ptr;
    return SUCCESS;

}

Node* dequeue(Queue* queue_ptr){

    if(!queue_ptr->elements->head) return NULLPTR;
    Node* dequeued = queue_ptr -> elements -> head;
    queue_ptr -> elements -> head = dequeued -> next;
    return dequeued;

}

//STACK FUNCTIONS

char stack(Stack * stack, Node * new_node){

    unshift(stack->elements, new_node);
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

Stack* clearStack(Stack* stack, int clear_buffer, int clear_elements_buffer){

    clearList(stack->elements, clear_buffer, clear_elements_buffer);
    if(clear_buffer){

        return NULLPTR;
    
    }
    return stack;

}

//BST FUNCTIONS

BST* addChild(BST*root, int child_value){

    if(root->value < child_value){

        if(root->right_child) return addChild(root->right_child, child_value);
        root->right_child = newBST(child_value);
        return SUCCESS;

    }
    
    else if(root->value > child_value){
        
        if(root->left_child) return addChild(root->left_child, child_value);
        root->left_child = newBST(child_value);
        return SUCCESS;

    }
    
    return NULLPTR;
    //Trying to add an equal value to a BST returns an exception.

}

BST* search(BST* root, int value){
    
    if(!root) return ERROR;

    if(root->value != value){

        if(root->value > value) return search(root->left_child, value);
        else return search(root->right_child, value);

    }
    return root;

}

BST* max(BST*root){

    if(root->right_child->right_child) return max(root->right_child);
    return root;

}

BST* min(BST*root, int translate){

    if(root->left_child->left_child) return min(root->left_child, translate);
    return root;

}

BST* deleteChild(BST* root, int value, int clear){

    if(!root) return ERROR;
    if(root->value == value){
        
        BST*location = root;

        if(root->left_child && root->right_child){

            BST*l_c = root->left_child;
            BST*r_c = root->right_child;
            BST* mark = max(root->left_child);
            root = mark->right_child;
            root->left_child = l_c;
            root->right_child = r_c;
            mark->right_child = NULLPTR;
            
        }

        if(root->left_child){
            
            BST* mark = root->left_child;
            root = mark;

        }
        
        if(root->right_child){

            BST* mark = root->right_child;
            root = mark;

        }
        
        if(clear){
            
            free(location);
            return NULLPTR;

        }
        
        return location;

    }
    if(root->value < value) return deleteChild(root->right_child, value, clear);
    else return deleteChild(root->left_child, value, clear);

}