#include "..\structures.h"
#include <stdio.h>

int main(){

    List* my_list_ptr = newList();
    Node* my_node_ptr = newNode("my key");
    append(my_list_ptr, my_node_ptr);
    //sends my_node_ptr to the end of the list.

    printf("%d\n", val(last(my_list_ptr)));
    printf("%d\n", val(first(my_list_ptr)));
    
    unshift(my_list_ptr, newNode("new key"));
    Node* new_ptr = searchNode(my_list_ptr, "new key");
    printf("%s\n", val(new_ptr));

}