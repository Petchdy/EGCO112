#include<stdio.h>
#include<stdlib.h>

struct node {
        int value;
        struct node * ptr;
};
typedef struct node Node;

Node * create_node(int val);
void add_node_front(Node ** head, int new_node_val);
void add_node_back(Node * head, int new_node_val);
void print_linked_list(Node * head);

int main(int argc, char * argv[]) {

    Node * linked_list = create_node(1);
    add_node_back(linked_list, 2);
    add_node_front(&linked_list, 0);

    print_linked_list(linked_list);
    printf("\n");
    
    return 0;

}

Node * create_node(int val) {

    Node * new_node = (Node *)malloc(sizeof(Node) * 1);
    new_node->value = val;
    new_node->ptr = NULL;

    return new_node;

}

void add_node_front(Node ** head, int new_node_val) {

    Node * new_node = create_node(new_node_val);

    new_node->ptr = *head;
    *head = new_node;
}

void add_node_back(Node * head, int new_node_val) {

    Node * new_node = create_node(new_node_val);
    head->ptr = new_node;

}

void print_linked_list(Node * head) {

    Node * temp = (Node *)malloc(sizeof(Node) * 1);

    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->ptr;
    }
}