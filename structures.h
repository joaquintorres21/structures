#ifndef STRUCTURE
#define STRUCTURE

#define SUCCESS 0
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
//This function returns the last node in the list. Iterates the structure until the element processed
//has a pointer associated with value 0.

LINKED_LIST Node* deleteNode(List* list, Node* node_ptr);
//This function deletes the node residing in node_ptr and returns it's direction.

LINKED_LIST char append(List* list, Node* new_node);
//Vinculates a created node to the end of the list.

LINKED_LIST char unshift(List* list, Node* new_node);
//Vinculates a created node to the beggining of the list.

LINKED_LIST char index(List* list, Node* new_node, int position);
//Vinculates a created node to the selected position.


#endif