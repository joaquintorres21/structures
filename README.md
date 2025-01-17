# Structures

This library contains a simple implementation of various data structures for C.


## Linked lists

A linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.

Here is the code to create a node and a list  that contains it:

```c
#include "structures.h"

int main(){

  Node* my_node_ptr = newNode("this is the node value");
  List* my_list_ptr = newList();
  append(my_list_ptr, my_node_ptr);

}
```

Then we can append, unshift or insert new nodes.

```c
  unshift(my_list_ptr, newNode(your_str));
  append(my_list_ptr, newNode(your_other_str));
  insert(my_list_ptr, newNode(your_other_other_str), 2);
```
There are multiple functions for searching a node.

```c
  Node* my_search_by_val = search(my_list_ptr, string);
  Node* my_search_by_pos = local(my_list_ptr, 2);
  Node* my_first_element = first(my_list_ptr);
  Node* my_last_element = last(my_list_ptr);
```

And finally we can delete nodes by address/value, or clear the list.

```c
  deleteNode(my_list_ptr, my_search, 1);
  deleteVal(my_list_ptr, string, 1);
  clearList(my_list_ptr, 1, 1);
```

Integer arguments are flags for freeing the buffer used. In deleteNode is for removing the node from heap, and in clearList is for removing both.

## Queue

A queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence. By convention, the end of the sequence at which elements are added is called the back, tail, or rear of the queue, and the end at which elements are removed is called the head or front of the queue, analogously to the words used when people line up to wait for goods or services.

Here is a code for instantiating a queue and operating with it.
```c
Node* my_node = newNode("qwerty");
Queue* my_queue = newQueue();
enqueue(my_queue, my_node);
enqueue(my_queue, newNode("azerty"));
dequeue(my_queue); //returns the node with value "qwerty"
clearQueue(my_queue, 1, 1);
```

## Stack

A stack is an abstract data type that serves as a collection of elements with two main operations: Push, which adds an element to the collection, and Pop, which removes the most recently added element. Additionally, a peek operation can, without modifying the stack, return the value of the last element added. The name stack is an analogy to a set of physical items stacked one atop another, such as a stack of plates.

Here is a code for instantiating a stack and operating with it.
```c
Node* my_node = newNode("qwerty");
Stack* my_stack = newStack();
stack(my_stack, my_node);
stack(my_stack, newNode("azerty"));
unstack(my_stack); //returns the node with value "azerty"
clearStack(my_stack, 1, 1);
```

## Binary Search Tree

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree data structure with the key of each internal node being greater than all the keys in the respective node's left subtree and less than the ones in its right subtree. The time complexity of operations on the binary search tree is linear with respect to the height of the tree.

```c
BST* my_bst = newBST(1);
addChild(my_bst, 2); //added as right child
addChild(my_bst, 0); //added as left child
addChild(my_bst, 5);
addChild(my_bst, 4);
BST* x = max(my_bst); //childs are also BSTs
BST* y = min(my_bst);
BST* z = search(my_bst, 5); //returns tree with value 5 and left child 4
```

