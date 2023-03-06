/*
    Linked list example
    Zack McKevitt

    Test program for ll implementation.
    Tests adding/deleting nodes.
    Verify memory leaks with valgrind

    TODO:
    Implement error checking w status
*/

#include "../linkedlist.h"

int main() {

    printf("Creating list...\n");
    struct sll list = sll_create();
    sll_print(&list);    

    struct sllnode node;

    printf("Appending 10 to empty list...\n");
    node = sllnode(-1, 10);
    int status = sll_append(&list, node);
    sll_print(&list);

    printf("Appending 20 to list...\n");
    node = sllnode(-1, 20);
    status = sll_append(&list, node);
    sll_print(&list);

    printf("Appending 30 to list...\n");
    node = sllnode(-1, 30);
    status = sll_append(&list, node);
    sll_print(&list);

    printf("Removing 30 from list...\n");
    status = sll_delete_by_value(&list, 30);
    sll_print(&list);

    printf("Destroying list...\n");
    status = sll_destroy(&list);
    sll_print(&list);

    return 0;
}
