#ifndef STRUCTURE
#define STRUCTURE

#define SUCCESS 0
#define NULLPTR 0X0
#define LINKED_LIST
#define BINARY_TREE

LINKED_LIST typedef struct{

    int value;
    Node*next;

} Node;
//https://en.wikipedia.org/wiki/Node_(computer_science)

LINKED_LIST typedef struct {

    Node * head;

} List;
//https://en.wikipedia.org/wiki/Linked_list

LINKED_LIST Node* last(List* list);
//This function returns a memory address to the last node in the list. 
//Iterates the structure until the element processed has a pointer associated with value 0.

LINKED_LIST Node* deleteNode(List* list, Node* node_ptr);
//This function deletes the node residing in node_ptr and returns it's memory address.
//It iterates the struct until finding a node whose associated pointer is the same that the arg's.

LINKED_LIST char append(List* list, Node* new_node_ptr);
//Vinculates a created node to the end of the list.
//Just invokes last() and makes the pointer equal to new_node_ptr

LINKED_LIST char unshift(List* list, Node* new_node);
//Vinculates a created node to the beginning of the list.
//First makes new_node point to the list head and then changes the head to new_node

LINKED_LIST char index(List* list, Node* new_node, int position);
//Vinculates a created node to the selected position.
//Iterates until the indicated position. If, in the way, founds a node with the value 0,
//it appends the node to the end of the list. Else, it vinculates the new node with the two beside.

#endif