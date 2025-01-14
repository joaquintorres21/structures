# Structures

This library contains a simple implementation of various data structures for C.


## Linked lists

A linked list is an ordered set of nodes. A node is a type with a value and a pointer. When it's associated in a structure the pointer is used to signalize the next node of it. The advantage respect vectors is that the memory assignment occurs delocalized, facilitating the addition, management and removal.

Here is the code to create a node and a list  that contains it:

```c
#include "structures.h"

int main(){

  Node* my_node_ptr = newNode(21);
  List* my_list_ptr = newList(my_node_ptr);

}
```

Then we can append, unshift or insert new nodes.

```c
  unshift(my_list_ptr, newNode(20));
  append(my_list_ptr, newNode(19));
  insert(my_list_ptr, newNode(18), 2);
```
There are multiple functions for searching a node.

```c
  Node* my_search_by_val = search(my_list_ptr, 19);
  Node* my_search_by_pos = local(my_list_ptr, 2);
  Node* my_first_element = first(my_list_ptr);
  Node* my_last_element = last(my_list_ptr);
```

And finally we can delete nodes by address/value, or clear the list.

```c
  deleteNode(my_list_ptr, my_search, 1);
  deleteVal(my_list_ptr, 21, 1);
  clearList(my_list_ptr, 1, 1);
```

Integer arguments are flags for freeing the buffer used. In deleteNode is for removing the node from heap, and in clearList is for removing both.

## Queue

A Queue is a linked list with a pointer to it's end. Operates under the FIFO method (First In First Out) where the oldest indexed element is the returned when a request is done. When a node is enqueued it goes to the end of the structure, and the last pointer points to it.

## Stack

A Queue is a linked list that operates under the LIFO method (Last In First Out). When a node is stacked it goes to the top of the stack and will be the returned value when a request is made.