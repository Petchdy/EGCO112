struct double_ll {
    int data;
    struct double_ll * next;
    struct double_ll * prev;
};
typedef struct double_ll dll;

void insert(dll ** head, int value);
void delete(dll ** head, int value);
void print_dll(dll * head);
void print_rdll(dll * head);

void insert(dll ** head, int value) {
    
    // this function will be use to add new_node into dll

    // temp is the one that will be use as a main ptr
    // new_node is the one we will add it into dll
    dll * temp = *head;
    dll * new_node = (dll *)malloc(sizeof(dll));

    // initial value and ptr in new_node
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    // check if dll is empty
    // this new_node will become new head
    if (temp == NULL) {
        temp = new_node;
    }
    // in case dll is not empty (in this one it will be insert at the end)
    else {

        // go to the lastest node
        while(temp->next != NULL) {
            temp = temp->next;
        }

        // insert new_node
        // from temp -> NULL to temp -> new_node -> NULL
        temp->next = new_node;
        // from NULL <- new_node to temp <- new_node
        new_node->prev = temp;
    }

}

void delete(dll ** head, int value) {

    // this function will be use to delete specific node in dll
    
    // temp is the one that will be use as a main ptr
    dll * temp = *head;
    
    // check if the dll is empty
    if (temp == NULL) {
        printf("dll is empty\n");
        return;
    }
    // check if the target is the head node
    else if (temp->data == value) {
        if (temp->next == NULL) {
            *head = NULL;
        }
        (temp->next)->prev = temp->prev;
        free(temp);
        return;
    }

    // go into dll to find the target node 
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // after the loop end there are 2 possibilities
    // 1. target could not be found
    // 2. we are currently at that node

    // case 1 -> print out
    if (temp == NULL) {
        printf("target not found\n");
        return;
    }
    // case 2 -> delete
    else {

        // EX) NULL -> a -> b -> c -> NULL
        // incase we want to delete b and temp = b
        // 1. a -> c | a = temp->prev, a->next = temp->next
        // 2. a <- c | a->next
        // 3. free(b)

        // prev = node before temp(target node)
        // 1. connect with nextptr
        dll * previous = temp->prev;
        previous->next = temp->next;

        // 2. set up prev ptr
        if (temp->next != NULL) {
            (temp->next)->prev = previous;
        }

        // 3. free temp
        printf("deleting %d\n", temp->data);
        free(temp);
    }

}

void print_dll(dll * head) {

    // check if the dll is empty
    if (head == NULL) {
        printf("dll is empty\n");
    }

    // the condition will be false when temp -> NULL happend
    while (head->next != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    // print the last element remain in dll
    printf("%d\n", head->data);
}

void print_rdll(dll * head) {
    
    // check if the dll is empty
    if (head == NULL) {
        printf("dll is empty\n");
    }

    // travel to the last element of dll
    while (head->next != NULL) {
        head = head->next;
    }
    // start printing dll
    while (head->prev != NULL) {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("%d\n", head->data);

}