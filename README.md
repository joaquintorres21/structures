# Structures

This library contains an implementation of various data structures for C.

## Linked lists

A linked list is an ordered set of nodes. A node is a type with a value and a pointer. When it's associated in a structure the pointer is used to signalize the next node of it. The advantage respect vectors is that the memory assignment occurs delocalized, facilitating the addition, management and elimination of it's positions.

## Queue

A Queue is a linked list with a pointer to it's end. Operates under the FIFO method (First In First Out) where the oldest indexed element is the returned when a request is done. When a node is enqueued it goes to the end of the structure, and the last pointer points to it.

## Stack

A Queue is a linked list that operates under the LIFO method (Last In First Out). When a node is stacked it goes to the top of the stack and will be the returned value when a request is made.