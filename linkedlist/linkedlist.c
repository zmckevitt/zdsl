/*
    Linked list data structure implementation
    Zack McKevitt
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "linkedlist.h"

////////////////////////////////////
//
//    Single linked list
//
////////////////////////////////////

/*
    sll_create
    returns:
        initialized sll struct
*/
struct sll sll_create() {
    struct sll newlist;
    newlist.head = NULL;
    newlist.size = 0;
    return newlist;
}

/*
    sll_append
    returns:
        errno: malloc err 
        0: OK
*/
int sll_append(struct sll* list, int value) {
    
    struct sllnode* node = malloc(sizeof(struct sllnode));
    if(!node) return errno;
    node->val = value;
    node->next = NULL;    

    struct sllnode* iter = list->head;

    if(iter == NULL) {
        list->head = node;
        list->size = 1;
        return 0;
    }

    while(iter->next != NULL) {
        iter = iter->next;
    }
    
    iter->next = node;

    list->size += 1;

    return 0;
}

/*
    sll_delete
    returns:
        -1: empty list
        -2: element not in list
         0: OK
*/
int sll_delete(struct sll* list, int value) {

    struct sllnode* head = list->head;
    
    // List empty
    if(head == NULL) return -1;

    struct sllnode* prev = NULL;
    while(head->val != value) {
        prev = head;
        head = head->next;
    }

    // Element not in list
    if(head == NULL) return -2;

    // Element is head
    if(prev == NULL) {
        list->head = head->next;
        free(head);
    }
    // Element in middle of list
    else {
        prev->next = head->next;
        free(head);
    }

    list->size -= 1;
 
    return 0;
}

/*
    sll_destroy
    destroys the sll
    returns:
        -1: err
         0: OK
*/
int sll_destroy(struct sll* list) {

    struct sllnode* head = list->head;
    struct sllnode* prev = head;

    while(head != NULL) {
        prev = head;
        head = head->next;        
        free(prev);
    } 

    list->head = NULL;
    list->size = 0;

    return 0;
}

/*
    sll print
    returns:
        void
*/
void sll_print(struct sll* list) {
    struct sllnode* head = list->head;
    printf("->");
    while(head != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

////////////////////////////////////
//
//    Double linked list
//
////////////////////////////////////

struct dll dll_create() {
    struct dll newlist;
    newlist.head = NULL;
    newlist.size = 0;
    return newlist;
}

int dll_append(struct dll* list, int value) {
    return 0;
}

int dll_delete(struct dll* list, int value) {
    return 0;
}

int dll_destroy(struct dll* list) {
    return 0;
}

void dll_print(struct dll* list) {
    ;
}
