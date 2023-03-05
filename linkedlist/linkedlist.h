/*
    Linked list header file
    Zack McKevitt
*/

// TODO
// Support various list types

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////
//
//    Single linked list    
//
///////////////////////////////////

struct sll;
struct sllnode;

struct sll {
    struct sllnode* head;
    size_t size;
};

struct sllnode {
    struct sllnode* next;
    int val;
};

struct sll sll_create();
int    sll_append(struct sll*, int);
int    sll_delete(struct sll*, int);
int    sll_destroy(struct sll*);
void   sll_print(struct sll*);

///////////////////////////////////
//
//    Double linked list    
//
///////////////////////////////////

struct dll;
struct dllnode;

struct dll {
    struct dllnode* head;
    size_t size;
};

struct dllnode {
    struct dllnode* next;
    struct dllnode* prev;
    int val;
};

struct dll dll_create();
int    dll_append(struct dll*, int);
int    dll_delete(struct dll*, int);
int    dll_destroy(struct dll*);
void   dll_print(struct dll*);

#endif // LINKEDLIST_H
