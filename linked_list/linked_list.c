#include<stdio.h>
#include<stdlib.h>

struct node {
        int value;
        struct node * ptr;
};
typedef struct node Node;

Node * create_node(int val);
void add_node_front(Node ** head, int new_node_val);
void add_node_back(Node ** head, int new_node_val);
void add_node_at(Node ** head, int new_node_val, int new_node_index);
void print_linked_list(Node * head);

int main(int argc, char * argv[]) {

    Node * linked_list = create_node(1);
    add_node_back(&linked_list, 2);
    add_node_front(&linked_list, 0);
    add_node_at(&linked_list, 3, 3);
    add_node_at(&linked_list, -1, 0);

    print_linked_list(linked_list);
    printf("\n");

    add_node_at(&linked_list, 5, 2);

    print_linked_list(linked_list);
    printf("\n");
    
    return 0;

}

Node * create_node(int val) {

    // to create a node which is a pointer to struct we can use malloc to reserve some space for node
    Node * new_node = (Node *)malloc(sizeof(Node) * 1);
    // set up new_node
    new_node->value = val;
    new_node->ptr = NULL;

    return new_node;

}

void add_node_front(Node ** head, int new_node_val) {

    // create a new_node to add into linked_list
    Node * new_node = create_node(new_node_val);

    // because we are adding this node at the front so it pointer has to point to the old head
    // after this line new_node will be our new head point to the old head
    new_node->ptr = *head;
    // set up new head = new_node
    *head = new_node;
}

void add_node_back(Node ** head, int new_node_val) {

    // create a new_node to add into linked_list
    Node * new_node = create_node(new_node_val);
    // create a temporary_node which will be used to refer to the last node
    // cann't use head to travel to the last node cause that will made it imposible to go back to the head node
    Node * last_node = create_node(new_node_val);
    
    // use last_node as temporary_node
    last_node = *head;

    // a node that point to NULL is the last_node of linked_list
    while (last_node->ptr != NULL) {
        // go to the next node
        last_node = last_node->ptr;
    }
    
    // add new node after the old last_node
    // new_node is added at the end of head node too (pass by reference)
    last_node->ptr = new_node;

}

void add_node_at(Node ** head, int new_node_val, int new_node_index) {

    // we need 1 node to be our new_node
    //         1 node to be temp node
    //         1 temporary list (will be used to travel in linked_list)
    Node * new_node = create_node(new_node_val);
    Node * temp_node = (Node *)malloc(sizeof(Node));
    Node * temp_list = (*head);
    int i;

    // in case want to add at the front
    if (new_node_index == 0) {
        add_node_front(head, new_node_val);
        return;
    }

    // in case want to add at some point in the linked_list
    for (i = 0; temp_list != NULL; i++) {

        // use i+1 because it has to be added before the loop travel past or already at that index
        if (i+1 == new_node_index) {
            // split linked_list into 2 parts -> first half + second half
            // keep the second part
            temp_node = temp_list->ptr;
            // add new_node after the first half
            temp_list->ptr = new_node;
            // put the second half back at the end of new_node (currently new_node = first half + new_node and temp_node = the second half)
            new_node->ptr = temp_node;
        }

        temp_list = temp_list->ptr;

    }

    // in case want to add at the end
    if (i+1 == new_node_index) {
        add_node_back(head, new_node_val);
    }

}

void print_linked_list(Node * linked_list) {
    
    // in this function we passed linked_list just as a linked_list (not pass by reference)
    // this make it fine to travel using our input cause it won't affect the real one
    // go to the next one until the end of the linked_list
    while(linked_list != NULL) {
        printf("%d ", linked_list->value);
        // go to the next node
        linked_list = linked_list->ptr;
    }
}