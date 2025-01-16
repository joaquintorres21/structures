#include "..\structures.h"
#include <stdio.h>

int main(){

    BST* my_bst = newBST(10);
    addChild(my_bst, 15);
    addChild(my_bst, 13);
    addChild(my_bst, 12);
    BST* my_max = max(my_bst); //returns the bst with value 15, left_child 13 and right_child NULLPTR
    BST* my_min = min(my_bst); //returns the root
    //You can also use my_max to search mins on it, since it's a tree itself.
    BST* min_of_max = min(my_max); //returns the 12 node with childs NULLPTR

    printf("%d\n", my_bst->value);
    printf("%d\n", my_max->value);
    printf("%d\n", my_min->value);
    printf("%d\n", min_of_max->value);    

    BST* deleted = deleteChildByValue(my_bst, my_max->value, 0);
    printf("%d", max(my_bst)->value);
    printf("%d\n", deleted->value);

}