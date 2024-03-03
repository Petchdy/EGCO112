#include<stdio.h>
#include<stdlib.h>
#include"double_ll.h"

int main () {

    dll * head_node = (dll *)malloc(sizeof(dll));

    insert(&head_node, 1);
    insert(&head_node, 2);
    insert(&head_node, 3);

    print_dll(head_node);
    print_rdll(head_node);

    delete(&head_node, 4);
    delete(&head_node, 1);
    delete(&head_node, 3);

    print_dll(head_node);
    print_rdll(head_node);

}