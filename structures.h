#ifndef STRUCTURE
#define STRUCTURE

#define SUCCESS 0
#define ERROR (void*)1
#define NULLPTR (void*)0X0
#define UNIVERSAL
#define LINKED_LIST
#define STACK
#define TREE

UNIVERSAL typedef union{
    
    int int_value;
    float float_value;
    double double_value;

} Data;

UNIVERSAL typedef struct Node{

    int value;
    struct Node* next;

} Node;
//https://en.wikipedia.org/wiki/Node_(computer_science)

LINKED_LIST typedef struct {

    Node * head;

} List;
//https://en.wikipedia.org/wiki/Linked_list

STACK typedef struct {

    List * elements;

} Stack;
//https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

UNIVERSAL Node* newNode(int value);
//Creates a node in heap memory.

LINKED_LIST List* newList(Node* init_head);

STACK Stack*newStack(Node* init_top);

UNIVERSAL Node* deleteNode(List* list, Node* node_to_delete, int delete_buffer);
//This function deletes the node residing in node_ptr and returns it's memory address.
//It iterates the struct until finding a node whose associated pointer is the same that the arg's.

LINKED_LIST Node* last(List* list);
//This function returns a memory address to the last node in the list. 
//Iterates the structure until the element processed has a pointer associated with value 0.

LINKED_LIST char append(List* list, Node* new_node_ptr);
//Vinculates a created node to the end of the list.
//Just invokes last() and makes the pointer equal to new_node_ptr

LINKED_LIST char unshift(List* list, Node* new_node);
//Vinculates a created node to the beginning of the list.
//First makes new_node point to the list head and then changes the head to new_node

LINKED_LIST char insert(List* list, Node* new_node, int position);
//Vinculates a created node to the selected position.
//Iterates until the indicated position. If, in the way, founds a node with the value 0,
//it appends the node to the end of the list. Else, it vinculates the new node with the two beside.

STACK char stack(Stack* stack, Node* new_node);
//Appends the new_node to the top of the stack.

STACK Node* unstack(Stack* stack);
//Returns the last indexed element

LINKED_LIST List* clearList(List* list_to_clear);
//Applies to the values on a Stack, you can pass (stack_name) -> elements as argument.

#endif