/*
Name: Structures
Description: This library contains a set of data structures for C.
Dependencies: None
Repository: https://github.com/joaquintorres21/structures
License: MIT LICENSE
*/

#ifndef STRUCTURE
#define STRUCTURE

#define SUCCESS 0
#define ERROR (void*)1
#define NULLPTR (void*)0X0
#define UNIVERSAL //Descriptive for Nodes
#define LINKED_LIST //...
#define QUEUE //...
#define STACK //...
#define TREE //...

#define INTERACTIVE //Descriptive for functions that make two struct instances to interact (compare, mix, search, etc.)

UNIVERSAL typedef union{
    
    int set_int;
    float set_float;
    double set_double;
    
} Dynamic;
//https://en.wikipedia.org/wiki/Union_type

UNIVERSAL typedef struct node{

    int value;
    struct node* next;

} Node;
//https://en.wikipedia.org/wiki/Node_(computer_science)

LINKED_LIST typedef struct {

    Node * head;

} List;
//https://en.wikipedia.org/wiki/Linked_list

QUEUE typedef struct {

    List* elements;
    Node* last;

} Queue;
//The queues work under the FIFO principle (First In, First Out), where the oldest entry is the returned value when
//a request is done.
//https://en.wikipedia.org/wiki/Queue_(abstract_data_type)

STACK typedef struct {

    List* elements;

} Stack;
//The stacks work under the LIFO principle (Last in, First Out), where the last entry is the returned value when a
//request is done. 
//https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

TREE typedef struct binary_tree{

    int value;
    struct binary_tree* left_child;
    struct binary_tree* right_child;

} BinaryTree;
//A Binary Tree is a Tree type with grade 2. This means that every node can have up to 2 childs.
//https://en.wikipedia.org/wiki/Binary_tree

TREE typedef struct bst{
    
    int value;
    struct bst* left_child;
    struct bst* right_child;

} BST;
//The BST (Binary Search Tree) is a binary tree with an exclusive storage rule: 
//If the insertion is lower than the root, will be the left side child.
//If the insertion is higher than the root, will be the right side child.
//https://en.wikipedia.org/wiki/Binary_search_tree


//This data structures are instantiated with their respective functions (descripted below)
//If they dont, they wont be created in the heap memory and will cause errors when clearing them.
//https://en.wikipedia.org/wiki/Memory_management#HEAP



UNIVERSAL Node* newNode(int value);
//Creates a node in heap memory.

UNIVERSAL int val(Node* node_ptr);
//Returns the value of the node argument.





LINKED_LIST List* newList(Node* init_head);
//Creates a list in heap memory.

LINKED_LIST List* clearList(List* list_to_clear, int delete_list_trigger, int delete_nodes_trigger);
//Devinculates nodes from list.

LINKED_LIST char append(List* list, Node* new_node_ptr);
//Vinculates a created node to the end of the list.
//Just invokes last() and makes the pointer equal to new_node_ptr.

LINKED_LIST char unshift(List* list, Node* new_node);
//Vinculates a created node to the beginning of the list.
//First makes new_node point to the list head and then changes the head to new_node.

LINKED_LIST char insert(List* list, Node* new_node, int position);
//Vinculates a created node to the selected position.
//Iterates until the indicated position. If, in the way, founds a node with the value 0,
//it appends the node to the end of the list. Else, it vinculates the new node with the two beside.

LINKED_LIST Node* deleteNode(List* list, Node* node_to_delete, int delete_buffer);
//This function deletes from list the node residing in node_to_deleted and returns it's memory address if delete_buffer is 0. 
//It iterates the struct until finding a node whose associated pointer is the same that the arg's.

LINKED_LIST Node* deleteVal(List* list, int value, int clear_buffer);
//Deletes the first node which contains the value.

LINKED_LIST Node* deletePosition(List* list, int position_to_delete, int delete_buffer);
//Deletes the node in position_to_delete.

LINKED_LIST Node* first(List* list);
//Returns the head of the list.

LINKED_LIST Node* last(List* list);
//Returns a memory address to the last node in the list.
//Iterates the structure until the element processed has a pointer associated with value 0.

LINKED_LIST Node* searchNode(List* list, int value_to_search);
//Search the first node with value = value_to_search and returns its memory address.

LINKED_LIST Node* local(List* list, int position_to_search);
//Search a node by position and returns its memory address.






QUEUE Queue* newQueue(Node* init_first);
//Creates a queue with init_first as first/last.

QUEUE Queue* clearQueue(Queue* queue, int delete_queue_trigger, int delete_elements_trigger);
//Clears the queue. delete_queue_trigger and delete_elements_trigger free their respective memory locations.

QUEUE char enqueue(Queue* queue, Node* node_ptr);
//Adds a node to the queue, making it the last of it.

QUEUE Node* dequeue(Queue* queue);
//Returns the first indexed element.





STACK Stack* newStack(Node* init_top);
//Creates a stack in heap memory.

STACK Stack* clearStack(Stack* stack, int delete_stack_trigger, int delete_elements_trigger);
//

STACK char stack(Stack* stack, Node* new_node);
//Appends the new_node to the top of the stack.

STACK Node* unstack(Stack* stack);
//Deletes the last indexed element from the stack, and then returns it's value.

STACK Node* top(Stack* stack);
//Returns the top of the stack.




TREE BinaryTree* newBinaryTree(int tree_root, BinaryTree* left_child, BinaryTree* right_child);
//If the childs are NULLPTR it will be created a unique node.

TREE BST* newBST(int tree_root);
//The appending of new entries it's left to the specific functions.

TREE BST* addChild(BST* binary_search_tree, int child_value);

TREE BST* search(BST* binary_search_tree, int value_to_search);

TREE BST* deleteChild(BST* binary_search_tree, int child_value, int clear_buffer);


#endif