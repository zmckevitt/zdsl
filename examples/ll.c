#include "../linkedlist/linkedlist.h"

int main() {

    printf("Creating list...\n");
    struct sll list = sll_create();
    sll_print(&list);    

    printf("Appending 10 to empty list...\n");
    int status = sll_append(&list, 10);
    sll_print(&list);

    printf("Appending 20 to list...\n");
    status = sll_append(&list, 20);
    sll_print(&list);

    printf("Appending 30 to list...\n");
    status = sll_append(&list, 30);
    sll_print(&list);

    printf("Removing 30 from list...\n");
    status = sll_delete(&list, 30);
    sll_print(&list);

    printf("Destroying list...\n");
    status = sll_destroy(&list);
    sll_print(&list);

    return 0;
}
